# To-do before finishing

## Cleanup and error handling

Write a cleanup code that:
- checks inside game and frees every non-null allocations
- frees game itself

Call the above cleanup code _after_ printing the error code in `game->error`...

## Maps

Write checks for:
- MAP_INVALID_BOUNDARY,
- MAP_INVALID_ROW_LENGTH,
- MAP_INVALID_TILE,
- MAP_INCOMPLETE,
- MAP_EXIT_INACCESSIBLE

Make maps for each and test them.

## Image sizes

If map is too big, use smaller textures and grid size.


## Miscellaneous

- Write a proper README.md.
- Delete this TODO and NOTES before delivering.