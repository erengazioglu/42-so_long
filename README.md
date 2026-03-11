# so_long

_This project has been created as part of the 42 curriculum by egaziogl._

## Description

"so_long" is a basic 2D game project, where the player controls a character, moving it in the 4 cardinal directions. The player moves around the map in top-down view, walking into collectibles to pick them up, and then escaping through the exit.

### Requirements

The project must be built using the "MiniLibX" library, and accept a "map description" file as a parameter (extension .ber).

#### Game requirements

- WASD moves the player in the cardinal directions.
- The player can't move into walls.
- At every move, the current total number of movements is displayed (in the shell, or on the screen for the bonus).
- Character's goal is "to collect all collectibles on the map and then escape by choosing the shortest possible route".

#### Graphics requirements

- ESC closes the window and quits the program in a clean way.
- The "X" (close) window control does the same.
- Minimizing/switching windows etc shouldn't disrupt the "window management".
- The use of _images_ from MiniLibX is mandatory.

#### Bonus requirements

- There's an additional "enemy patrol", which makes the player lose when touched.
- Sprites are animated.
- The movement count is printed on screen instead of in the shell.

### The challenge

It's the first computer graphics project of the 42 curriculum, meaning we're dealing with (among other things):
- window management,
- memory management,
- game loop,
- event handling,
- error handling.

It requires the creation of a context that must be managed correctly: the loading of textures, the initialization of game objects... and most importantly, the cleanup after a game exit/crash.

### Implementation

The main architecture looks like this (check `new_game`):
- a game object (`t_game`) is initialized as empty,
- textures and animations are loaded into memory,
- the map is parsed and its dynamic objects extracted (player, collectibles...),
- a window is created based on the size of the map,
- hooks are set up for key events and game loop,
- the `mlx_loop` is run,
- the program returns its exit value.

#### Game object

The pertinant data in memory is held in a struct `t_game` which is always passed to functions. This makes so that at any moment, you can:
- read game state,
- access other game objects,
- quit gracefully.

It holds references to the game objects in a linked list.

#### Map validity

Game returns an error and quits gracefully if:
- map file can't be read,
- the map has no player,
- the map has invalid tiles,
- the boundaries of the map are not completely walled,
- there is no valid path from player to exit (dijkstra algorithm),
- there is no exit (dijkstra already takes care of this).

#### Dijkstra

Create a clone of the map with only:
- Obstacles `(X)`
- Goal `(*)`
- Accessible tiles `( )`
- Discovered tiles `(.)` = starting point (only one)

Loop over the map, "spreading" the discovered tiles in the 4 cardinal directions if available:
- If tile is not `(.)`, move on;
- If tile is `(.)`, check up, down, left, right;
- For each, if the tile being checked is `(*)`, stop everything and report `SUCCESS`;
- If instead the tile being checked is `( )`, "discover" it `(.)`, report `SPREAD`, and continue;
- If not, report `NO_SPREAD`, and continue.

At the end of the loop, if no `SPREAD` has happened, the exit is unreachable; quit the loop and throw an error.

#### Game objects

All "dynamic" game objects (collectibles, character, patrols...) have the following attributes:  
- position,
- type,
- animation (and last rendered frame of it).

The game will hold these objects in a list, keep track of them, handle their behavior, and render them on every loop.

#### Animations

Animations are very simply **a set of images that are meant to be drawn in sequence,** at a stable framerate. This is handled in the `process` function called through the _loop hook,_ which: 
- keeps track of time past since last render,
- re-renders when that time exceeds the refresh rate (in milliseconds).

#### Error handling

The game object has an `error` variable (enum) that holds the last encountered error. Functions that need to report such errors will either return a `bool` or a freeable object `NULL`. Once that happens, the false or NULL will bubble up all the way up in the call stack, and call `crash`.

`crash` will free all memory, print the error, and quit gracefully.

## Instructions

### Compilation

You need to download [minilibx-linux](https://github.com/42paris/minilibx-linux) first:
- make sure you're in the root directory of this repository,
- run `https://github.com/42paris/minilibx-linux.git minilibx-linux` on your terminal,
- run `make -C minilibx-linux` (or `cd minilibx-linux && make`).

After that, if you type `make` in the root directory (where the makefile is), it will compile both the mandatory version and the bonus one.  
If you want to compile them separately, run either `make so_long` or `make so_long_bonus`.

### Running

The program (`so_long` or `so_long_bonus`) expects 1 argument only: the relative filepath to the game map. Examples:  
- `so_long assets/maps/subject-1.ber` (will run the first example in the subject pdf)
- `so_long_bonus assets/maps/bonus/complete-1.ber` (will run a map with all bonus features)
- `so_long assets/maps/bonus/complete-1.ber` (will crash because of bonus tiles not being handled by the mandatory-only version)

### Testing

A set of invalid maps are available under `assets/maps/invalid`, that you can run through either `so_long` or `so_long_bonus` (same result).

Running bonus maps (`assets/maps/bonus`) through the mandatory-only version (`so_long`) will result in a crash — this is expected behavior, since the bonus maps include tiles that are not specified in the subject brief.

## Resources

### References
- MiniLibX source code & man pages (`man minilibx-linux/man/man1/*`),
- `man gettimeofday`,
- fellow students.

### Utilities

I used [ImageMagick](https://imagemagick.org/#gsc.tab=0) to convert my .png files into .xpm:

```bash
for file in assets/*.bmp; 
do magick "$file" "${file%.png}.xpm"; 
done
```

### Textures 

Floor and wall textures are created by me from scratch.
The rest are originally from the [kenney.nl 1-Bit Pack](https://kenney.nl/assets/1-bit-pack), adapted by me to be duo-tone, consistent, and animated.


