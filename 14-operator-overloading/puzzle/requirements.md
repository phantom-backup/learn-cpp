### Top-level program goals
Board things:
    - Display the game board
    - Display a game tile
    - Randomize the starting state
    - Slide a tile
    - Determine if the game is complete
User things:
    - Get commands from the user
    - Handle invalid commands
    - Allow the user to quit

### Primary classes/namespaces/main
class Board:
    - int tiles[4][4]
    - displayBoard
    - displayTile
    - randomize
    - slideTile
    - isGameComplete
class Tile:
    - int num
namespace UserInput:
    - no state, so not a class
    - keeps user input functions organized
function main:
    - create board
    - randomize board
    - while game is not complete:
        - display board
        - display valid commands
        - get valid user input
        - exit if requested
        - slide tile
    - print game complete message