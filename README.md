# so_long

_This project has been created as part of the 42 curriculum by egaziogl._

## Description

_(TBD)_

### Requirements

_(TBD)_

### The challenge

_(TBD)_

### Implementation

- Created a game object (`t_game`) that holds all pertinent data & can be passed around.
- Game assets are held in a linked list for a more straightforward cleanup.

#### Game object

The pertinant data in memory is held in a struct `t_game` which is always passed to functions. This makes so that at any moment, you can:
- read game state,
- access other game objects,
- quit gracefully.

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

_(TBD)_

### Compilation

_(TBD)_

### Integration

_(TBD)_

### Testing

_(TBD)_


## Resources

_(TBD)_