#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>

class PmergeMe {
public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void run(int argc, char **av);

private:
  std::vector<int> _vec;
  std::deque<int> _deq;

  void _parseInput(int argc, char **argv);

  void _sortVec();

  void _sortDeq();

  void _printSequence(const std::vector<int> &v) const;
};

#endif
