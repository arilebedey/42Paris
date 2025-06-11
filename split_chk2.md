stack_a 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 newest_idx: 0 oldest_idx: 18

### call sort segment with whole stack_a

Empty sort_small_segment 1

#### move values to split.max (BOTTOM_A)

ra
ra
ra
ra
ra
ra

stack_a 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 newest_idx: 6 oldest_idx: 5

#### move values to split.mid (TOP_B)

pb
pb
pb
pb
pb
pb

stack_a 19 18 17 16 15 14 7 6 5 4 3 2 1 newest_idx: 6 oldest_idx: 5
stack_b 8 9 10 11 12 13 newest_idx: 0 oldest_idx: 5

#### move values to split.min (BOTTOM_B)

pb
rb
pb
rb
pb
rb
pb
rb
pb
rb
pb
rb
pb
rb

stack_a 19 18 17 16 15 14 newest_idx: 0 oldest_idx: 5
stack_b 8 9 10 11 12 13 7 6 5 4 3 2 1 newest_idx: 0 oldest_idx: 12

### finished splitting: next: sort_segment with split.max,mid,min with segments initialized in `split_segment`

max: loc: BOTTOM_A, count: 6
mid: loc: TOP_B, count: 6
min: loc: BOTTOM_B, count: 7

#### `sort_segment(ctx, &split.max);`

stack_a 19 18 17 16 15 14 newest_idx: 0 oldest_idx: 5

split.max is whole stack_a so seg.loc == TOP_A after `approach_seg_from_top()`

Empty sort_small_segment 2

pivot_large: 2, pivot_small: 4

ra
ra

stack_a 19 18 17 16 15 14 newest_idx: 2 oldest_idx: 1
(unchanged) stack_b 8 9 10 11 12 13 7 6 5 4 3 2 1 newest_idx: 0 oldest_idx: 12

pb
pb

stack_a 19 18 15 14 newest_idx: 2 oldest_idx: 1
stack_b 16 17 8 9 10 11 12 13 7 6 5 4 3 2 1 newest_idx: 0 oldest_idx: 14

pb
rb
pb
rb

stack_a: 0 0 0 0 0 0 18 19 0 0 0 0 0 0 0 0 0 0 0 newest_idx: 6 oldest_idx: 7
stack_b: 13 7 6 5 4 3 2 1 15 14 0 0 16 17 8 9 10 11 12 newest_idx: 12 oldest_idx: 9

#### `sort_segment(ctx, &split.mid);`

mid: loc: TOP_B, count: 6
initial stack_b when mid was defined: 8 9 10 11 12 13 7 6 5 4 3 2 1 newest_idx: 0 oldest_idx: 12
actual stack_b: 14 15 16 17 8 9 10 11 12 13 7 6 5 4 3 2 1 newest_idx: 2 oldest_idx: 1

sa
sb
pa
pa

push_a_if_consec & sort_second_top

stack_a 16 17 18 19 newest_idx: 0 oldest_idx: 3
current stack_b: 15 14 8 9 10 11 12 13 7 6 5 4 3 2 1 newest_idx: 2 oldest_idx: 1

rrb
rrb
pa
pa

returned from sort_segment(min):
0 0 14 15 16 17 18 19 0 0 0 0 0 0 0 0 0 0 0 newest_idx: 2 oldest_idx: 7
13 7 6 5 4 3 2 1 0 0 0 0 0 0 8 9 10 11 12 newest_idx: 14 oldest_idx: 7

sort_segment(initial mid split)

Start push_a_if_consec: seg_val_1: 8, seg_val_2: 9, stk_val_1: 14
pivot_small: 4 pivot_large: 2
splitting done.

pushes 8, 9 to BOTTOM_B
pushes 10, 11 to BOTTOM_A
pushes 12, 13 to TOP_A

12 13 14 15 16 17 18 19 10 11 0 0 0 0 0 0 0 0 0 newest_idx: 0 oldest_idx: 9
0 7 6 5 4 3 2 1 8 9 0 0 0 0 0 0 0 0 0 newest_idx: 1 oldest_idx: 9

### Remaining ophist

rrb
pa
rrb
pa
pa
pa
pa
pa
pa
pa
pa
