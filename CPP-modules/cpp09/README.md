## ex00

### Why map()

- Sorted by key: Dates are stored in chronological order automatically

- Efficient lookup: lower_bound() uses binary search to find the closest earlier date in O(log n)

## ex01

### Why stack()

- You need LIFO (Last-In-First-Out) behavior to process operands in the correct order

- Operations pop the two most recent values and push the result back

## ex02

### Vector vs. Deque

Vector is O(n) for insertion
Deque uses a block-based structure to solve vector's insertion problem
Vector faster random access because contiguous

| Aspect              | vector                  | deque                            | Impact                            |
| ------------------- | ----------------------- | -------------------------------- | --------------------------------- |
| Random access       | O(1) direct memory      | O(1) but compute block offset    | vector slightly faster            |
| Cache locality      | Contiguous → cache hits | Fragmented blocks → cache misses | vector much faster                |
| Iterator arithmetic | Simple pointer math     | Complex (block jumping)          | vector faster for iter + offset   |
| Front insertion     | O(n) shift              | O(1) amortized                   | deque much faster (not used here) |
| Push_back           | O(1) amortized          | O(1) amortized                   | Same                              |

#### Verdict

Deque is better at resizing and and front insertion
But for FJ vector is faster because Cache locality is better (contiguous memory)

In practice, vector tends to win on modern CPUs for most workloads unless insertions dominate the operations

### The why

The Jacobsthal sequence picks group sizes (1, 2, 2, 6, 10, 22...) such that after inserting a Jacobsthal-indexed element, the number of uninserted elements before it is always less than a power of 2 minus 1, keeping every binary search within an exact power-of-2 boundary, which is the sweet spot where binary search needs exactly \(k\) comparisons for \(2^k - 1\) elements

### The how

Label the pend elements p_1, p_2, p_3, etc. Each p_i has a known upper bound in the chain: its paired large element (already in the chain). So the search range for p_i is not the whole chain — it's only up to where its partner sits.

### Binary search

The biggest number of comparisons (k) to find a number in a Binary Tree is log2(n) where n is number of elements.

It is so because each comparison eliminates half of the remaining candidates.

Asking the question : after how many halvings does n becomes 1? We get n/2^k = 1.

Then we solve it for the number of comparisons k = log2(n).

### Insight for merge-insert

Look at the comparisons needed for each range in a BT:

    Range: 1-2          → needs ⌈log₂(2)⌉ = 1 comparison
    Range: 3-4          → needs ⌈log₂(4)⌉ = 2 comparisons
    Range: 5-8          → needs ⌈log₂(8)⌉ = 3 comparisons
    Range: 9-16         → needs ⌈log₂(16)⌉ = 4 comparisons
    Range: 17-32        → needs ⌈log₂(32)⌉ = 5 comparisons

Pattern: All ranges from 2^k to 2^(k+1)-1 need k comparisons!

### The result

So the ideal scenario: keep every search range 2^k - 1 for the smallest possible k comparisons.

### sortVecNodes

It sorts the large nodes as standalone nodes, but keeps their ids.

That id is how the function later reconnects each sorted large node to its original full pair.

### main_chain

What main_chain means at a given level

At a given chunk_size, main_chain is a sequence of iterators to chunk starts, representing the chunks that are already in sorted order at that chunk granularity.

### Batch endpoint

Example:

If: `jacob = {3}`
then: `current = 3 - 1 = 2`

→ batch ends at `pend[2]`

Computing `current` is for choosing which indices of pend to process now.

So each iteration defines a batch:

`k∈[start,current]` processed in reverse order.

### main_chain search limit

```cpp
const size_t search_limit = std::min(main_chain.size(), static_cast<size_t>(k + 2));
```

k + 2 encodes a structural invariant of the algorithm.

For any bk:

bk is guaranteed to belong somewhere before a\_{k+1}

### Things to understand better

- For a single pending chunk, the insertion schedule is just one insertion batch ending at index 1.
- Bookkeeping array, why we need a prev_jacob?

### upper_bound

std::upper_bound returns an iterator to the first element in a sorted range that is strictly greater than the given value.

upper_bound has no way to verify the data is sorted — it just blindly does the index arithmetic and returns a position.

If the data wasn't sorted, it would simply return a wrong position silently, leading to incorrect sorting results with no error or warning.

### .assign()

used.assign(pairs.size(), false);

Creates a boolean array the same size as pairs:

`used = [false, false, false, ...]`

This marks whether a given original pair has already been copied into sorted_pairs.

It prevents the same pair from being added twice.

### logger for buildInsertionOrder

```cpp
static std::vector<int> buildInsertionOrder(int pend_size) {
  std::vector<int> order;
  std::vector<int> jacob = buildJacobsthalSequence(pend_size + 1);
  jacob.push_back(pend_size + 1);
  std::cout << "pend_size + 1: " << pend_size + 1 << std::endl;
  std::cout << "Jacobsthal: ";
  for (size_t i = 0; i < jacob.size(); ++i)
    std::cout << jacob[i] << " ";
  std::cout << std::endl;

  int previous = 1;
  for (size_t i = 0; i < jacob.size(); ++i) {
    for (int label = jacob[i]; label > previous; --label)
      order.push_back(label - 2);
    previous = jacob[i];
  }
  std::cout << "order: ";
  for (size_t i = 0; i < order.size(); ++i)
    std::cout << order[i] << " ";
  std::cout << std::endl;
  return order;
}
```
