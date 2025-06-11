For simplicity, let's imagine that anything seg.count above 2 gets split into 3 splits and we dont sort anything, and lets say that pivots are always 1/3

#### First sort_segment call

TOP_A
19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

##### creates 3 splits

split.max
loc: BOTTOM_A
count: 7
19 18 17 16 15 14

split.mid
loc: TOP_B
count: 5
13 12 11 10 9 8

split.min
loc: BOTTOM_B
count: 5
7 6 5 4 3 2 1

#### sort_segment(split.max) call

calls split on the max segment (11 12 13 14 15 16):

TOP_A split.max
BOTTOM_A split.mid
TOP_B split.min

pushes 11 12 to TOP_B, 13 14 to BOTTOM_A and 15 16 to TOP_A

the each of those are sorted (already are)

##### Initial sort_segment calls sort_segment(split.mid)

calls split on the mid segment (4 5 6), but now its (7 4 5 6), but seg.count is still 3. So only 7 4 5 will get moved to location

# Prompt

Am I not correct in my reasoning?
