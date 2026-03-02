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

#### Map validity

Game returns an error and quits gracefully if:
- map file can't be read,
- the map has no player,
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