# Snake Game in C

This is a simple console-based Snake game implemented in C. The game features a snake that moves within a boundary, eats fruit to grow its tail, and ends when the snake collides with the boundary or its own tail.

## Features

- **Console-based gameplay**: Play the game directly in your terminal.
- **Boundary detection**: The game ends if the snake hits the boundary.
- **Fruit consumption**: The snake's tail grows when it eats the fruit.
- **User input**: Control the snake using the `W`, `A`, `S`, and `D` keys for up, left, down, and right movements, respectively.
- **Score tracking**: The score increases as the snake eats the fruit.
- **Replay option**: After the game ends, you can choose to play again.

## Setup and Installation

### Prerequisites

- C compiler (e.g., `gcc`)

### Compilation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/snake-game.git
   cd snake-game
   ```

2. Compile the program:

   ```bash
   gcc -o snake snake.c
   ```

3. Run the program:

   ```bash
   ./snake
   ```

## How to Play

- **Start the game**: Run the compiled executable.
- **Control the snake**: Use the following keys to control the snake's direction:
  - `W`: Move up
  - `A`: Move left
  - `S`: Move down
  - `D`: Move right
- **End the game**: Press `X` to end the game.
- **Replay**: After the game ends, press `SPACE` or `Y` to play again.

## Code Overview

### Variables

- `flag`, `gameOver`: Control the game state.
- `tailX`, `tailY`: Arrays to store the coordinates of the snake's tail.
- `CountTail`: Size of the snake's tail.
- `width`, `height`: Dimensions of the game boundary.
- `snake_x`, `snake_y`: Coordinates of the snake's head.
- `fruitX`, `fruitY`: Coordinates of the fruit.
- `score`: Player's score.

### Functions

- `setup()`: Initializes the game state.
- `boundary()`: Draws the game boundary and the positions of the snake and fruit.
- `kbhit()`: Detects if a key has been pressed.
- `input()`: Handles user input to control the snake.
- `MakeLogic()`: Updates the game logic, including the snake's movement, collision detection, and fruit consumption.
- `SlowerExec()`: Slows down the game execution for a better gameplay experience.
- `main()`: Main function that controls the game loop and handles game restart.

made this game when i had started programming.

By following the instructions above, you can compile and run the Snake game on your local machine. Enjoy playing and feel free to modify the code to add more features or improve the game!
