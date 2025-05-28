```c
typedef enum s_stack_location
{
	LOCATION_TOP_A,
	LOCATION_TOP_B,
	LOCATION_BOTTOM_A,
	LOCATION_BOTTOM_B,
}						t_stack_location;
```

```c
typedef struct s_stack_segmnt
{
	t_stack_location	location;
	int					elem_count;
}						t_stack_segmnt;
```

Segments are tracked at these points because they are the only positions where elements can be efficiently manipulated or moved between stacks.

Algorithm Design:

The recursive sorting strategy (recursive_segment_sort) splits segments and moves them between stacks, always positioning them at the top or bottom for efficient access.
