#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
// Random declarations
int flag, gameOver; // gameover=1 then game finishes i.e the while loop ends
int tailX[100], tailY[100];
int CountTail = 0; // tail size increases as the snake eats the fruit
// Boundary declarations
int width = 20, height = 20;

// initial positions declarations
int snake_x, snake_y, fruitX, fruitY, score = 0;

// initial positions
void setup()
{
    gameOver = 0;
    snake_x = width / 2;
    snake_y = height / 2;
label1:
    srand(time(0));
    fruitX = rand() % 20; // so the co ordinates remain under 20 i.e inside the rectangle
    if (fruitX == 0)
    {
        goto label1; // so that if at all the co ordinates are at the ends i.e at edges of rectangle then fruitx will get a value again
    }
label2:
    srand(time(0));
    fruitY = rand() % 20;
    if (fruitY == 0)
    {
        goto label2;
    }
    score = 0;
}
// Boundary
void boundary()
{
    int i, j, k;
    system("clear");
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (i == 0 || i == height || j == 0 || j == width) // i==0 then it prints the whole line as i remains 0 for the whole iteration of j
                                                               // i== height then again it prints the whole line as for it as well j runs uska fully
                                                               // for j==0 only once per iteration of j
                                                               // and j==width for once iteration of j thus it prints only the ends
            {
                printf("X");
            }
            else // putting the snake head and fruit at their initial positions
                 // while reading skip thinking about fruit and the snake head at once
                 // first make the boundary then put this

            {
                if (i == snake_x && j == snake_y)
                {
                    printf("O");
                }
                else if (i == fruitX && j == fruitY)
                {
                    printf("o");
                }
                else
                {
                    int ch = 0;
                    for (k = 0; k < CountTail; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printf("o");
                            ch = 1;
                        }
                    }
                    if (ch == 0)
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
// User Input
void input()
{
    if (kbhit())
        switch (getchar())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 'd':
            flag = 4;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
}
// THE LOGIC
void MakeLogic()
{

    int prevX = tailX[0]; // to store the co oridnates of the tail end when snake eat the food so increment is possible
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = snake_x;
    tailY[0] = snake_y;
    for (int i = 1; i < CountTail; i++) // ***NEED TO PROCESS THISSS***
    {
        prev2X = tailX[i]; // Store the tailX[1] in another variable so it doesnt get overwritten
        prev2Y = tailY[i]; // when tailX[0] is written in its location
        tailX[i] = prevX;  // now store the tailX[0] that
        tailY[i] = prevY;  // was initially stored in prevX,Y into tailX[1]
        prevX = prev2X;    // now prevX has tailX[0] and prev2X has tail[1],
        prevY = prev2Y;    // so put tail[0] to tail[1] i.e move the snake ahead
    }

    // sleep(1); // to slower the speed of executation orrrr use nested loops to slower the execution speed in main()
    switch (flag)
    {
    case 1:
        snake_y--; // user wants to go to left
        break;
    case 2: // user wants to go to right
        snake_x++;
        break;
    case 3: // user wants to go up
        snake_x--;
        break;
    case 4: // user wants to go down
        snake_y++;
        break;
    default:
        break;
    }
    // to end  the game as soon as the snake touches the end
    if (snake_x < 0 || snake_x > width || snake_y < 0 || snake_y > height)
    {
        gameOver = 1;
    }
    for (int i = 0; i < CountTail; i++)
    {
        if (snake_x == tailX[i] && snake_y == tailY[i])
        {
            gameOver = 1;
        }
    }

    // after snake eats the food i.e head is at location of food, generate new random location for snake
    if (snake_x == fruitX && snake_y == fruitY)
    {
    label3:
        srand(time(0));
        fruitX = rand() % 20;
        if (fruitX == 0)
        {
            goto label3;
        }
    label4:
        srand(time(0));
        fruitY = rand() % 20;
        if (fruitY == 0)
        {
            goto label4;
        }
        score++;
        CountTail++;
    }
}
// to slower the execution
void SlowerExec()
{
    for (int r = 0; r < 10000; r++)
    {
        for (int k = 0; k < 20000; k++)
        {
        }
    }
}

int main()
{
    char c;
label5:
    setup(); // Not called infinitely as game is suppposed to move forward and if this is called, game will become stagnant i.e baar baar same jagah pr snake aur fruit aajaenge

    while (!gameOver)
    {
        boundary();
        input();
        MakeLogic();
        SlowerExec();
    }
    printf("score=%d\n", score);
    printf("\nPress space or y to play again");
    scanf("%c", &c);
    if (c == ' ' || c == 'y')
    {
        goto label5;
    }

    return 0;
}
