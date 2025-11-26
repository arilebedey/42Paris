# Sequential Containers

### ⚙️ 1. **`std::vector`**

- **Memory layout:** Contiguous block (like a dynamic array).
- **Key strengths:**
  - Fast **random access** → you can do `v[i]` in constant time \(O(1)\).
  - Very efficient **iteration** because of contiguous memory.
  - Great cache locality → blazing fast in practice.
- **Weaknesses:**
  - Inserting/removing anything **other than at the end** is expensive (O(n)), because elements may need to be shifted.
  - Adding elements at the end can trigger a reallocation (copies elements to a new, larger memory block).
- **Typical use:** General-purpose, most common container when you know or don’t frequently change the size.

---

### 🔗 2. **`std::list`**

- **Memory layout:** Doubly linked list (each element points to the next and previous).
- **Key strengths:**
  - Insertion/removal **anywhere** is efficient (O(1)) — just adjust pointers.
  - No reallocation or shifting of elements.
- **Weaknesses:**
  - No direct/random access (`list[i]` doesn’t exist) → must iterate from a known position.
  - Poor cache performance — elements are scattered in memory.
  - Higher memory overhead per element (for the pointers).
- **Typical use:** When you insert/remove elements frequently in the middle of the sequence.

---

### ⚖️ 3. **`std::deque` (double-ended queue)**

- **Memory layout:** Multiple contiguous blocks (not a single array, but still more cache-efficient than a list).
- **Key strengths:**
  - Fast insertions/removals at **both ends** (unlike `vector`, which is fast only at the back).
  - Random access supported (`d[i]` works) — a bit slower than a vector.
- **Weaknesses:**
  - More complex internal structure → slightly higher overhead.
  - Not great for frequent middle insertions/removals (like vector).
- **Typical use:** When you need to push/pop from **both front and back** efficiently (like in queue or sliding window algorithms).

# Pre-increment and post-increment on iterators

### **The difference between pre-increment and post-increment on iterators**

| Syntax                    | Meaning                                                                                         |
| ------------------------- | ----------------------------------------------------------------------------------------------- |
| `++it` _(pre-increment)_  | Advance `it` to the next element, **and then return a reference to the updated iterator**.      |
| `it++` _(post-increment)_ | Make a **copy** of `it`, advance the original, **then return the old copy** (before increment). |

---
