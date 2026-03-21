#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    _vec = other._vec;
    _deq = other._deq;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

struct VecNode {
  int value;
  size_t id;
};

struct VecNodePair {
  VecNode small;
  VecNode large;
};

struct VecPendingNode {
  VecNode node;
  bool has_bound;
  size_t bound_id;
};

struct NodeValueLess {
  bool operator()(int value, const VecNode &node) const {
    return value < node.value;
  }
};

struct DeqNode {
  int value;
  size_t id;
};

struct DeqPairNode {
  DeqNode small;
  DeqNode large;
};

struct DeqPendingNode {
  DeqNode node;
  bool has_bound;
  size_t bound_id;
};

struct DeqValueLess {
  bool operator()(int value, const DeqNode &node) const {
    return value < node.value;
  }
};

static std::vector<int> buildJacobsthalSequence(int max_value) {
  std::vector<int> seq;
  int a = 1;
  int b = 3;

  while (b < max_value) {
    seq.push_back(b);
    int next = b + 2 * a;
    a = b;
    b = next;
  }
  return seq;
}

static std::vector<int> buildInsertionOrder(int pend_size) {
  std::vector<int> order;
  std::vector<int> jacob = buildJacobsthalSequence(pend_size + 1);
  jacob.push_back(pend_size + 1);

  int previous = 1;
  for (size_t i = 0; i < jacob.size(); ++i) {
    for (int label = jacob[i]; label > previous; --label)
      order.push_back(label - 2);
    previous = jacob[i];
  }
  return order;
}

static size_t findNodeIndex(const std::vector<VecNode> &chain, size_t id) {
  for (size_t i = 0; i < chain.size(); ++i) {
    if (chain[i].id == id)
      return i;
  }
  return chain.size();
}

static size_t findNodeIndex(const std::deque<DeqNode> &chain, size_t id) {
  for (size_t i = 0; i < chain.size(); ++i) {
    if (chain[i].id == id)
      return i;
  }
  return chain.size();
}

static void sortVecNodes(std::vector<VecNode> &nodes);
static void sortDeqNodes(std::deque<DeqNode> &nodes);

static void sortPairNodesByLarge(std::vector<VecNodePair> &pairs) {
  std::vector<VecNode> large_nodes;
  std::vector<VecNodePair> sorted_pairs;

  if (pairs.size() == 1)
    return;

  for (size_t i = 0; i < pairs.size(); ++i)
    large_nodes.push_back(pairs[i].large);

  sortVecNodes(large_nodes);

  for (size_t i = 0; i < large_nodes.size(); ++i) {
    for (size_t j = 0; j < pairs.size(); ++j) {
      if (pairs[j].large.id == large_nodes[i].id) {
        sorted_pairs.push_back(pairs[j]);
        break;
      }
    }
  }
  pairs.swap(sorted_pairs);
}

static void insertPendingNodes(std::vector<VecNode> &chain,
                               const std::vector<VecNodePair> &pairs,
                               bool has_odd, const VecNode &odd) {
  std::vector<VecPendingNode> pend;

  for (size_t i = 1; i < pairs.size(); ++i) {
    VecPendingNode pending;

    pending.node = pairs[i].small;
    pending.has_bound = true;
    pending.bound_id = pairs[i].large.id;
    pend.push_back(pending);
  }
  if (has_odd) {
    VecPendingNode pending;

    pending.node = odd;
    pending.has_bound = false;
    pending.bound_id = 0;
    pend.push_back(pending);
  }

  const std::vector<int> insertion_order = buildInsertionOrder(pend.size());

  for (size_t i = 0; i < insertion_order.size(); ++i) {
    const VecPendingNode &pending = pend[insertion_order[i]];
    const size_t bound_index = pending.has_bound
                                   ? findNodeIndex(chain, pending.bound_id)
                                   : chain.size();
    std::vector<VecNode>::iterator pos =
        std::upper_bound(chain.begin(), chain.begin() + bound_index,
                         pending.node.value, NodeValueLess());
    chain.insert(pos, pending.node);
  }
}

static void sortVecNodes(std::vector<VecNode> &nodes) {
  std::vector<VecNodePair> pairs;
  std::vector<VecNode> chain;
  VecNode odd;
  bool has_odd = false;

  if (nodes.size() <= 1)
    return;

  for (size_t i = 0; i + 1 < nodes.size(); i += 2) {
    VecNodePair pair;

    pair.small = nodes[i];
    pair.large = nodes[i + 1];
    if (pair.large.value < pair.small.value)
      std::swap(pair.small, pair.large);
    pairs.push_back(pair);
  }

  if (nodes.size() % 2 == 1) {
    odd = nodes.back();
    has_odd = true;
  }

  sortPairNodesByLarge(pairs);

  chain.push_back(pairs[0].small);
  for (size_t i = 0; i < pairs.size(); ++i)
    chain.push_back(pairs[i].large);

  insertPendingNodes(chain, pairs, has_odd, odd);
  nodes.swap(chain);
}

static void sortPairNodesByLarge(std::deque<DeqPairNode> &pairs) {
  std::deque<DeqNode> large_nodes;
  std::deque<DeqPairNode> sorted_pairs;
  std::vector<bool> used;

  if (pairs.size() <= 1)
    return;

  for (size_t i = 0; i < pairs.size(); ++i)
    large_nodes.push_back(pairs[i].large);

  sortDeqNodes(large_nodes);

  used.assign(pairs.size(), false);
  for (size_t i = 0; i < large_nodes.size(); ++i) {
    for (size_t j = 0; j < pairs.size(); ++j) {
      if (!used[j] && pairs[j].large.id == large_nodes[i].id) {
        sorted_pairs.push_back(pairs[j]);
        used[j] = true;
        break;
      }
    }
  }
  pairs.swap(sorted_pairs);
}

static void insertPendingNodes(std::deque<DeqNode> &chain,
                               const std::deque<DeqPairNode> &pairs,
                               bool has_odd, const DeqNode &odd) {
  std::vector<DeqPendingNode> pend;

  for (size_t i = 1; i < pairs.size(); ++i) {
    DeqPendingNode pending;

    pending.node = pairs[i].small;
    pending.has_bound = true;
    pending.bound_id = pairs[i].large.id;
    pend.push_back(pending);
  }

  if (has_odd) {
    DeqPendingNode pending;

    pending.node = odd;
    pending.has_bound = false;
    pending.bound_id = 0;
    pend.push_back(pending);
  }

  const std::vector<int> insertion_order = buildInsertionOrder(pend.size());

  for (size_t i = 0; i < insertion_order.size(); ++i) {
    const DeqPendingNode &pending = pend[insertion_order[i]];
    const size_t bound_index = pending.has_bound
                                   ? findNodeIndex(chain, pending.bound_id)
                                   : chain.size();
    std::deque<DeqNode>::iterator pos =
        std::upper_bound(chain.begin(), chain.begin() + bound_index,
                         pending.node.value, DeqValueLess());
    chain.insert(pos, pending.node);
  }
}

static void sortDeqNodes(std::deque<DeqNode> &nodes) {
  std::deque<DeqPairNode> pairs;
  std::deque<DeqNode> chain;
  DeqNode odd;
  bool has_odd = false;

  if (nodes.size() <= 1)
    return;

  for (size_t i = 0; i + 1 < nodes.size(); i += 2) {
    DeqPairNode pair;

    pair.small = nodes[i];
    pair.large = nodes[i + 1];
    if (pair.large.value < pair.small.value)
      std::swap(pair.small, pair.large);
    pairs.push_back(pair);
  }

  if (nodes.size() % 2 == 1) {
    odd = nodes.back();
    has_odd = true;
  }

  sortPairNodesByLarge(pairs);

  chain.push_back(pairs[0].small);
  for (size_t i = 0; i < pairs.size(); ++i)
    chain.push_back(pairs[i].large);

  insertPendingNodes(chain, pairs, has_odd, odd);
  nodes.swap(chain);
}

void PmergeMe::_parseInput(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    std::istringstream ss(argv[i]);
    int val;
    if (!(ss >> val) || val <= 0) {
      throw std::runtime_error("invalid input");
    }
    std::string
        leftover; // because if "123abc" istringstream reads only 123 into int
    if (ss >> leftover)
      throw std::runtime_error("invalid input");
    _vec.push_back(val);
    _deq.push_back(val);
  }
}

void PmergeMe::run(int argc, char **argv) {
  _parseInput(argc, argv);

  std::cout << "Before: ";
  _printSequence(_vec);

  struct timespec ts_start, ts_end;

  clock_gettime(CLOCK_MONOTONIC, &ts_start);
  _sortVec();
  clock_gettime(CLOCK_MONOTONIC, &ts_end);
  double vec_time = (ts_end.tv_sec - ts_start.tv_sec) * 1e6 +
                    (ts_end.tv_nsec - ts_start.tv_nsec) / 1e3;

  clock_gettime(CLOCK_MONOTONIC, &ts_start);
  _sortDeq();
  clock_gettime(CLOCK_MONOTONIC, &ts_end);
  double deq_time = (ts_end.tv_sec - ts_start.tv_sec) * 1e6 +
                    (ts_end.tv_nsec - ts_start.tv_nsec) / 1e3;

  std::cout << "After: ";
  _printSequence(_vec);

  std::cout << std::fixed << std::setprecision(5);
  std::cout << "Time to process a range of " << _vec.size()
            << " elements with std::vector : " << vec_time << " us"
            << std::endl;
  std::cout << "Time to process a range of " << _deq.size()
            << " elements with std::deque  : " << deq_time << " us"
            << std::endl;
}

void PmergeMe::_printSequence(const std::vector<int> &v) const {
  for (size_t i = 0; i < v.size(); ++i) {
    if (i)
      std::cout << " ";
    std::cout << v[i];
  }
  std::cout << std::endl;
}

void PmergeMe::_sortVec() {
  std::vector<VecNode> nodes;

  for (size_t i = 0; i < _vec.size(); ++i) {
    VecNode node;

    node.value = _vec[i];
    node.id = i;
    nodes.push_back(node);
  }

  sortVecNodes(nodes);

  for (size_t i = 0; i < nodes.size(); ++i)
    _vec[i] = nodes[i].value;
}

void PmergeMe::_sortDeq() {
  std::deque<DeqNode> nodes;

  for (size_t i = 0; i < _deq.size(); ++i) {
    DeqNode node;

    node.value = _deq[i];
    node.id = i;
    nodes.push_back(node);
  }

  sortDeqNodes(nodes);

  for (size_t i = 0; i < nodes.size(); ++i)
    _deq[i] = nodes[i].value;
}
