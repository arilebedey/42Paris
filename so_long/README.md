https://reactive.so/post/42-a-comprehensive-guide-to-so_long/
https://itch.io/game-assets/free/tag-sprites

### Intro

The main part of the program will be communicating with the MLX and X11, and the rest is a bit of parsing and error handling

### Functions overview

mlx_init: Initialises the MLX library. Must be called before using any other functions. The returned pointer of type void \* is the connection identifier returned by mlx_init()

mlx_new_window: Creates a new window instance.

mlx_clear_window() and mlx_destroy_window() respectively clear (in black) and destroy the given window. They both have the same parameters: mlx_ptr is the screen connection identifier, and win_ptr is a window identifier.

mlx_hook: Registers events. Allows you to listen for native X11 events, such as mouse movements, key presses, window interaction, and more…

mlx_loop: Loops over the MLX pointer, triggering each hook in order of registration. (?)

### Events

Events are the foundation of writing interactive applications in MiniLibX.

All hooks in MiniLibX are nothing more than a function that gets called whenever a event is triggered.

### `mlx_hook`

```c
int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
```

The parameters are as follows:

- win_ptr: You probably know what this is if you've used the MinilibX a bit :)
- x_event: The event code that you want to handle. You can use the constants defined by Xlib
- x_mask: The "mask" of the event you want to handle. I’ll let you read the X manual to learn more about it. You can use the constants defined by Xlib
- funct: A pointer to the function that will handle the event. We'll see the prototypes of the different functions handled by MinilibX later
- param: A miscellaneous parameter that you can pass to the function handling the event

Here are the supported events:

```c
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
```

For managing the closing of the window use:

```c
mlx_hook(game.win, 17, 0, close_game, &game);
```

### `mlx_key_hook`

Uses `mlx_hook` under the hood with appropriate flags to listen to key events.

```c
int mlx_key_hook(vars.win, callback_fn, &vars_for_cbfn);
```

### Reading images

```c
img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
```

To read from a file to a image object, you need either the XMP or PNG format.

It will set the img_width and img_height accordingly, which is ideal when reading sprites.

In order to read we can call the functions mlx_xpm_file_to_image and mlx_png_file_to_image accordingly.

Do mind that mlx_png_file_to_image currently leaks memory.

Both functions accept exactly the same parameters and their usage is identical.

If the returned variable is equal to NULL, it means that the image reading has failed.

### Putting text on screen

```c
	mlx_string_put(game->mlx, game->win, 20, 40, 0xFFFFFF, tmp);
```
