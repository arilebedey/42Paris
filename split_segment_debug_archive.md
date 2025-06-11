stack_a: {2, 1, 5, 4, 6, 3, 7}

### first split segment

seg->loc == TOP_A

pivot_large = 2
seg_size < 15
pivot_small = 7
-> anything > 7 - 2 will go to max (rank 6 and 7)
-> the rest to mid split (ranks 1 - 5)
op_hist = { }

#### split_segment: while loop iteration 1

next_val = 2

- goes to split->mid
  move_to_loc(ctx, seg->loc, split.mid.loc);
  ophist += (pb)
- state
  stack_a: {0, 1, 5, 4, 6, 3, 7}, newest_idx: 1, oldest_idx: 6
  stack_b: {2, 0, 0, 0, 0, 0, 0}, newest_idx: 0, oldest_idx: 0
  op_hist = { pb }

#### split_segment: while loop iteration 2

next_val = 1

- goes to split->mid
  move_to_loc(ctx, seg->loc, split.mid.loc);
  ophist += (pb)
- state
  stack_a: {0, 0, 5, 4, 6, 3, 7}, newest_idx: 2, oldest_idx: 6

  stack_b: {2, 0, 0, 0, 0, 0, 1}, newest_idx: 6, oldest_idx: 0
  op_hist = { pb, pb }

#### split_segment: while loop iteration 3

next_val = 5

- goes to split->mid
  move_to_loc(ctx, seg->loc, split.mid.loc);
  ophist += (pb)
- state
  stack_a: {0, 0, 0, 4, 6, 3, 7}, newest_idx: 3, oldest_idx: 6

  stack_b: {2, 0, 0, 0, 0, 5, 1}, newest_idx: 5, oldest_idx: 0
  op_hist = { pb, pb, pb }

#### split_segment: while loop iteration 4

next_val = 4

- goes to split->mid
  move_to_loc(ctx, seg->loc, split.mid.loc);
  ophist += (pb)
- state
  stack_a: {0, 0, 0, 0, 6, 3, 7}, newest_idx: 4, oldest_idx: 6

  stack_b: {2, 0, 0, 0, 4, 5, 1}, newest_idx: 4, oldest_idx: 0
  op_hist = { pb, pb, pb, pb }

#### split_segment: while loop iteration 5

next_val = 6

- goes to split->max
  move_to_loc(ctx, seg->loc, split.max.loc);
  ophist += (ra)
- state
  stack_a: {6, 0, 0, 0, 0, 3, 7}, newest_idx: 5, oldest_idx: 0

  stack_b: {2, 0, 0, 0, 4, 5, 1}, newest_idx: 4, oldest_idx: 0
  op_hist = { pb, pb, pb, pb, ra }

#### split_segment: while loop iteration 6

next_val = 3

- goes to split->max
  move_to_loc(ctx, seg->loc, split.mid.loc);
  ophist += (pb)
- state
  stack_a: {6, 0, 0, 0, 0, 0, 7}, newest_idx: 6, oldest_idx: 0

  stack_b: {2, 0, 0, 3, 4, 5, 1}, newest_idx: 3, oldest_idx: 0
  op_hist = { pb, pb, pb, pb, ra, pb }

#### split_segment: while loop iteration 7

next_val = 7
seg->count = 1 (last iteration)

- goes to split->max
  move_to_loc(ctx, seg->loc, split.mid.loc);
  ophist += (ra)
- state
  stack_a: {6, 7, 0, 0, 0, 0, 0}, newest_idx: 0, oldest_idx: 1

  stack_b: {2, 0, 0, 3, 4, 5, 1}, newest_idx: 3, oldest_idx: 0
  op_hist = { pb, pb, pb, pb, ra, pb, ra }

### sort_segment with splits occurs

split->max: {6, 7} at LOCATION_BOTTOM_A (count: 2)
split->mid: {3, 4, 5, 1, 2} at LOCATION_TOP_B (count: 5)
split->min: {} at LOCATION_BOTTOM_B (count: 0)

#### sort_segment(ctx, &split.max);

split->max: {6, 7} at LOCATION_BOTTOM_A (count: 2)
sort_two_elements sets `seg->count -= 2;`. Not sure why that's needed.
function returns

#### sort_segment(ctx, &split.mid);

split->mid: {3, 4, 5, 1, 2} at LOCATION_TOP_B (count: 5)

### sort_segment(ctx, &split.min);

Nothing happens: the segment is empty because seg_size was < 15
