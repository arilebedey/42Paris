### Paradigms used

- Base case recursion

### Recursive divide and conquer

- Partitioning: Divide the segment into three roughly equal groups (smallest, middle, largest values) to reduce the size of each sub-segment for recursive sorting.

- Order Preservation: Ensure that max_values contains the largest ranks, mid_values the middle ranks, and min_values the smallest ranks, maintaining a relative order that simplifies recursive assembly into a sorted stack.

- Efficiency: By splitting into three, the algorithm reduces the number of recursive steps compared to a binary split, balancing the trade-off between segment size and recursion depth.

### Outline

Not Physically Split: The "split" is logical, achieved by moving elements to different parts of stacks A and B (e.g., top or bottom of A or B). The original segment is emptied as elements are reassigned.

### Sorting max_values first

- Sorting max_values first ensures the largest elements are processed and placed at TOP_A in ascending order within that segment (e.g., [4, 3] with 4 at top, 3 below).
- Subsequent segments (mid_values, min_values) are sorted and stacked above max_values, pushing the larger elements downward.

### Why sort_two_elements puts them to top of A

- Moving to LOCATION_TOP_A standardizes the sorting process, avoiding complex tracking of elements across different stack locations.
- Algorithm Design: The recursive strategy (recursive_segment_sort) breaks down segments, sorts them, and consolidates results in stack A. sort_three_elements_segment ensures each sorted segment ends up at LOCATION_TOP_A to build the sorted stack incrementally.

### **Element Distribution**:

- The function iterates through the segment’s elements (`seg->elem_count` times), processing the topmost element each time:

  - `next_val = get_segment_value(ctx, seg, 1)`: Gets the value at the segment’s top (or bottom, depending on `location`).

  - Elements are moved based on their value relative to `max_val` and the pivots:

    - **If `next_val > max_val - pivot_large`** (largest values):

      - Move to `max_values.location` (e.g., `BOTTOM_A` or `TOP_A`).
      - Increment `max_values.elem_count`.
      - Call `reduce_max_segment` to check if the moved element can reduce the segment size (e.g., if it’s already in a sorted position).
      - If stack A is partially sorted (`is_stack_a_partially_sorted`) and elements remain, call `sort_small_segment` to exploit sorting opportunities.

    - **If `next_val > max_val - pivot_small`** (middle values):

      - Move to `mid_values.location` (e.g., `TOP_B` or `BOTTOM_A`).
      - Increment `mid_values.elem_count`.

    - **Otherwise** (smallest values):

      - Move to `min_values.location` (e.g., `BOTTOM_B`).
      - Increment `min_values.elem_count`.

- `move_to_location` performs the necessary push/rotate operations to place the element in the target location, updating the stack state.

---

The `split_segment` function is a core part of the push_swap program's recursive sorting strategy, specifically within the `recursive_segment_sort` (originally `chunk_sort`). It divides a stack segment into three smaller segments (`min_values`, `mid_values`, `max_values`) based on pivot values, redistributes elements to specific stack locations, and sets the stage for recursive sorting. Understanding how these segments end up sorted requires grasping the interplay of `split_segment`, `sort_segment`, and their recursive coordination. Below, I’ll explain how `split_segment` works and how the recursive process ensures all segments are sorted, keeping the explanation concise and focused on clarity.

### How `split_segment` Works

The `split_segment` function takes a segment of the stack (defined by `t_stack_segmnt` with a `location` and `elem_count`) and splits it into three smaller segments, which are then sorted recursively. Here’s a step-by-step breakdown of its operation, based on the provided code:

1. **Initialization**:

   - `init_split_sizes`: Sets `elem_count` to 0 for `min_values`, `mid_values`, and `max_values` in the `t_segmnt_split` structure, preparing to track the size of each new segment.
   - `set_split_locations`: Assigns target locations for the three segments based on the source segment’s location (`seg->location`). For example:
     - If `seg->location` is `LOCATION_TOP_A`, then:
       - `min_values` → `LOCATION_BOTTOM_B`
       - `mid_values` → `LOCATION_TOP_B`
       - `max_values` → `LOCATION_BOTTOM_A`
     - This ensures elements are moved to distinct parts of stacks A and B, avoiding overlap and facilitating sorting.

2. **Pivot Calculation**:

   - `set_pivot_values`: Computes two pivot values (`pivot_small` and `pivot_large`) to divide the segment into three groups:
     - `pivot_large = seg_size / 3`: Separates the largest third of values.
     - `pivot_small`:
       - For `TOP_A` or `BOTTOM_A`: `2 * seg_size / 3` (middle third).
       - For `TOP_B` or `BOTTOM_B`: `seg_size / 2` (adjusted for stack B).
       - Special cases: If `seg_size < 15` (for A) or `< 8` (for `BOTTOM_B`), pivots are adjusted to handle small segments efficiently.
   - These pivots are relative to the maximum value in the segment (`max_val`), obtained via `get_segment_max`.

3. **Element Distribution**:

   - The function iterates through the segment’s elements (`seg->elem_count` times), processing the topmost element each time:
     - `next_val = get_segment_value(ctx, seg, 1)`: Gets the value at the segment’s top (or bottom, depending on `location`).
     - Elements are moved based on their value relative to `max_val` and the pivots:
       - **If `next_val > max_val - pivot_large`** (largest values):
         - Move to `max_values.location` (e.g., `BOTTOM_A` or `TOP_A`).
         - Increment `max_values.elem_count`.
         - Call `reduce_max_segment` to check if the moved element can reduce the segment size (e.g., if it’s already in a sorted position).
         - If stack A is partially sorted (`is_stack_a_partially_sorted`) and elements remain, call `sort_small_segment` to exploit sorting opportunities.
       - **If `next_val > max_val - pivot_small`** (middle values):
         - Move to `mid_values.location` (e.g., `TOP_B` or `BOTTOM_A`).
         - Increment `mid_values.elem_count`.
       - **Otherwise** (smallest values):
         - Move to `min_values.location` (e.g., `BOTTOM_B`).
         - Increment `min_values.elem_count`.
   - `move_to_location` performs the necessary push/rotate operations to place the element in the target location, updating the stack state.

4. **Segment Update**:
   - Each move reduces `seg->elem_count` by 1, effectively emptying the original segment as elements are redistributed.
   - The resulting `split` structure contains three new segments (`min_values`, `mid_values`, `max_values`) with updated `elem_count` and `location` fields, ready for recursive sorting.

### How Segments End Up Sorted

The sorting process relies on the recursive interplay between `split_segment` and `sort_segment` (in `init_segment_sort.c`). Here’s how the entire mechanism ensures all segments are sorted and the stack ends up in order:

1. **Recursive Divide-and-Conquer**:

   - `recursive_segment_sort` starts with the entire stack A as a single segment (`LOCATION_TOP_A`, `elem_count = stack_a.capacity`).
   - `sort_segment` processes each segment:
     - **Base Cases**: If `elem_count ≤ 3`, it uses specialized functions:
       - `sort_three_elements_segment`: Sorts three elements using swaps/rotates, ensuring they’re in ascending order at `LOCATION_TOP_A`.
       - `sort_two_elements`: Moves two elements to `TOP_A` and swaps if needed.
       - `sort_one_element`: Moves one element to `TOP_A`.
       - These ensure small segments are sorted directly and placed at the top of stack A.
     - **Large Segments**: If `elem_count > 3`, `split_segment` divides the segment into `min_values`, `mid_values`, and `max_values`.

2. **Recursive Sorting Order**:

   - After `split_segment`, `sort_segment` recursively sorts the three new segments in this order: `max_values`, `mid_values`, `min_values`.
   - **Why this order?**
     - `max_values` contains the largest elements. Sorting it first ensures the highest values are correctly placed at the top of stack A (in ascending order).
     - `mid_values` (middle values) is sorted next, placing them above the already-sorted `max_values`.
     - `min_values` (smallest values) is sorted last, placing them at the top, completing the sorted stack.
   - This bottom-up approach ensures that when a segment is sorted, it’s placed in `TOP_A` in ascending order, building the sorted stack from largest to smallest values.

3. **Segment Movement and Optimization**:

   - `move_segment_to_top`: Before splitting or sorting, this function ensures the segment is accessible (e.g., moving `BOTTOM_A` to `TOP_A` if needed), simplifying operations.
   - `sort_small_segment`: Called within `split_segment` and `sort_segment`, it exploits partial sorting opportunities (e.g., if elements are already in order), reducing the segment size early.
   - `reduce_max_segment`: After moving an element to `max_values`, it checks if the segment can be reduced (e.g., if it’s part of a sorted sequence), minimizing recursive work.

4. **Stack Mechanics**:

   - The push_swap program uses two stacks (A and B) to sort numbers represented as ranks (1 to N, where 1 is smallest). The goal is to sort stack A in ascending order (1 at top, N at bottom).
   - `split_segment` distributes elements across both stacks, using locations like `TOP_B` or `BOTTOM_B` to temporarily hold unsorted segments.
   - Recursive sorting ensures each segment is eventually moved to `TOP_A` in sorted order. For example:
     - Sorting `max_values` might push its elements from `BOTTOM_A` to `TOP_A`, arranging them in ascending order.
     - Subsequent segments (`mid_values`, `min_values`) are sorted and stacked above, maintaining the order.

5. **Final Assembly**:

   - Because `sort_segment` handles base cases by placing sorted elements at `TOP_A` and recursive cases by sorting `max_values` to `min_values`, the stack A gradually builds up in ascending order.
   - The recursive process ensures no segment is left unsorted, and each sorted segment is correctly positioned relative to others.
   - After all recursive calls complete, stack A contains all elements in ascending order (rank 1 at top, N at bottom), and stack B is empty.

6. **Operation Optimization**:
   - `optimize_operations` (called in `sort.c`) post-processes the operation list (`op_hist`) to eliminate redundant moves (e.g., `pa` followed by `pb`) and merge compatible operations (e.g., `ra` + `rb` = `rr`), ensuring efficiency.
   - This doesn’t affect the sorting logic but ensures the output is concise.

### Example Walkthrough (Simplified)

Suppose you start with stack A = `[3, 1, 4, 2]` (ranks, size = 4):

- **Initial Segment**: `seg = {LOCATION_TOP_A, elem_count=4}`.
- **split_segment**:
  - `max_val = 4`, `pivot_large = 4/3 ≈ 1`, `pivot_small = 2*4/3 ≈ 2`.
  - Process each element:
    - Top = 3: `3 > 4-1`, move to `max_values` (`BOTTOM_A`), `max_values.elem_count++`.
    - Top = 1: `1 ≤ 4-2`, move to `min_values` (`BOTTOM_B`), `min_values.elem_count++`.
    - Top = 4: `4 > 4-1`, move to `max_values` (`BOTTOM_A`), `max_values.elem_count++`.
    - Top = 2: `2 ≤ 4-1 && 2 > 4-2`, move to `mid_values` (`TOP_B`), `mid_values.elem_count++`.
  - Result: `max_values = [3, 4] (BOTTOM_A)`, `mid_values = [2] (TOP_B)`, `min_values = [1] (BOTTOM_B)`.
- **Recursive Sorting**:
  - **max_values**: Size = 2, call `sort_two_elements` → Move `[3, 4]` to `TOP_A`, swap to `[4, 3]`.
  - **mid_values**: Size = 1, call `sort_one_element` → Move `[2]` to `TOP_A`, stack becomes `[2, 4, 3]`.
  - **min_values**: Size = 1, call `sort_one_element` → Move `[1]` to `TOP_A`, stack becomes `[1, 2, 4, 3]`.
- **Further Recursion**: If any segment were larger, it would split again. Here, base cases handle sorting, and additional operations (e.g., `rotate_a`) may finalize the order to `[1, 2, 3, 4]`.

### Why It Guarantees Sorting

- **Complete Coverage**: `split_segment` processes every element in the segment, ensuring no element is left unassigned.
- **Recursive Exhaustion**: `sort_segment` recursively sorts all sub-segments until they reach base cases (size ≤ 3), which are guaranteed to sort correctly.
- **Ordered Assembly**: Sorting `max_values` first, then `mid_values`, then `min_values` ensures larger ranks are placed lower in stack A, building the ascending order.
- **Stack Integrity**: The use of `TOP_A`, `BOTTOM_A`, `TOP_B`, and `BOTTOM_B` keeps segments distinct, preventing overlap or loss of elements.
- **Base Case Reliability**: Small segments are sorted explicitly, ensuring each recursive step produces a correctly ordered sub-stack.

### Addressing Your Struggle

Your difficulty in understanding how segments end up in order likely stems from the recursive nature and the distribution of elements across two stacks. Key points to clarify:

- **Segments Are Temporary**: `min_values`, `mid_values`, and `max_values` are not the final sorted stack but intermediate groups that are sorted and reassembled.
- **Recursion Builds Order**: The recursive calls ensure each segment is sorted and placed at `TOP_A` in the correct relative order (largest to smallest ranks).
- **Stack A Is the Goal**: All operations aim to arrange stack A in ascending order. Stack B is a temporary workspace for holding unsorted segments.
- **Visualize the Process**: Think of `split_segment` as partitioning a deck of cards into high, medium, and low groups, then sorting each group recursively and stacking them back in order.

If you’re still struggling, try tracing a small example (e.g., 5 elements) step-by-step, noting the state of stacks A and B after each `split_segment` and `sort_segment` call. Let me know if you need a detailed trace or further clarification on any part!
