// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <conio.h>
// #include <windows.h>
// using namespace std;

// const int WIDTH = 10;
// const int HEIGHT = 20;
// const int BLOCK_SIZE = 4;

// int board[HEIGHT][WIDTH] = {0};
// int block[BLOCK_SIZE][BLOCK_SIZE] = {0};
// int blockType = 0;
// int blockX = 0;
// int blockY = 0;

// void initBlock() {
//     int blocks[7][4][4] = {
//         {
//             {0, 0, 0, 0},
//             {1, 1, 1, 1},
//             {0, 0, 0, 0},
//             {0, 0, 0, 0}
//         },
//         {
//             {0, 0, 0, 0},
//             {0, 2, 2, 0},
//             {0, 2, 2, 0},
//             {0, 0, 0, 0}
//         },
//         {
//             {0, 0, 0, 0},
//             {0, 0, 3, 3},
//             {0, 3, 3, 0},
//             {0, 0, 0, 0}
//         },
//         {
//             {0, 0, 0, 0},
//             {0, 4, 4, 0},
//             {4, 4, 0, 0},
//             {0, 0, 0, 0}
//         },
//         {
//             {0, 0, 0, 0},
//             {5, 5, 0, 0},
//             {0, 5, 5, 0},
//             {0, 0, 0, 0}
//         },
//         {
//             {0, 0, 0, 0},
//             {0, 6, 0, 0},
//             {6, 6, 6, 0},
//             {0, 0, 0, 0}
//         },
//         {
//             {0, 0, 0, 0},
//             {0, 0, 7, 0},
//             {0, 7, 7, 7},
//             {0, 0, 0, 0}
//         },
//         {
//             {0, 0, 0, 0},
//             {0, 0, 0, 0},
//             {0, 0, 0, 0},
//             {8, 8, 8, 8}
//         }
//     };

//     blockType = rand() % 7;
//     for (int i = 0; i < BLOCK_SIZE; i++) {
//         for (int j = 0; j < BLOCK_SIZE; j++) {
//             block[i][j] = blocks[blockType][i][j];
//         }
//     }
//     blockX = WIDTH / 2 - 2;
//     blockY = 0;
// }

// void drawBoard() {
//     system("cls");
//     for (int i = 0; i < HEIGHT; i++) {
//         for (int j = 0; j < WIDTH; j++) {
//             if (board[i][j] == 0) {
//                 cout << " ";
//             } else {
//                 cout << "*";
//             }
//         }
//         cout << endl;
//     }
//     for (int i = 0; i < BLOCK_SIZE; i++) {
//         for (int j = 0; j < BLOCK_SIZE; j++) {
//             if (block[i][j] != 0) {
//                 int x = blockX + j;
//                 int y = blockY + i;
//                 if (y >= 0) {
//                     board[y][x] = blockType + 1;
//                 }
//             }
//         }
//     }
// }

// void moveBlock(int dx, int dy) {
//     for (int i = 0; i < BLOCK_SIZE; i++) {
//         for (int j = 0; j < BLOCK_SIZE; j++) {
//             if (block[i][j] != 0) {
//                 int x = blockX + j + dx;
//                 int y = blockY + i + dy;
//                 if (x < 0 || x >= WIDTH || y >= HEIGHT) {
//                     return;
//                 }
//                 if (y >= 0 && board[y][x] != 0) {
//                     return;
//                 }
//             }
//         }
//     }
//     blockX += dx;
//     blockY += dy;
// }

// void rotateBlock() {
//     int temp[BLOCK_SIZE][BLOCK_SIZE] = {0};
//     for (int i = 0; i < BLOCK_SIZE; i++) {
//         for (int j = 0; j < BLOCK_SIZE; j++) {
//             temp[i][j] = block[i][j];
//         }
//     }
//     for (int i = 0; i < BLOCK_SIZE; i++) {
//         for (int j = 0; j < BLOCK_SIZE; j++) {
//             block[i][j] = temp[BLOCK_SIZE - j - 1][i];
//         }
//     }
//     if (blockX < 0) {
//         blockX = 0;
//     } else if (blockX + BLOCK_SIZE > WIDTH) {
//         blockX = WIDTH - BLOCK_SIZE;
//     }
//     if (blockY + BLOCK_SIZE > HEIGHT) {
//         initBlock();
//         drawBoard();
//     }
// }

// int main() {
//     srand(time(NULL));
//     initBlock();
//     while (true) {
//         drawBoard();
//         if (_kbhit()) {
//             char ch = _getch();
//             switch (ch) {
//                 case 'a':
//                     moveBlock(-1, 0);
//                     break;
//                 case 'd':
//                     moveBlock(1, 0);
//                     break;
//                 case 's':
//                     moveBlock(0, 1);
//                     break;
//                 case 'w':
//                     rotateBlock();
//                     break;
//                 case ' ':
//                     //while (moveBlock(0, 1)) {}
//                     break;
//             }
//         }
//         if (!moveBlock(0, 1)) {
//             for (int i = 0; i < BLOCK_SIZE; i++) {
//                 for (int j = 0; j < BLOCK_SIZE; j++) {
//                     if (block[i][j] != 0) {
//                         int x = blockX + j;
//                         int y = blockY + i;
//                         board[y][x] = blockType + 1;
//                     }
//                 }
//             }
//             initBlock();
//         }
//         Sleep(100);
//     }
//     return 0;
// }

//写一个俄罗斯方块小游戏
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
#define WIDTH 10
#define HEIGHT 20
#define BLOCK_SIZE 4
int board[HEIGHT][WIDTH] = {0};
int block[BLOCK_SIZE][BLOCK_SIZE] = {0};
int blockType = 0;
int blockX = 0;
int blockY = 0;

void initBlock() {
    int blocks[7][BLOCK_SIZE][BLOCK_SIZE] = {
        {
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {2, 2, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {3, 3, 3, 0},
            {3, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {4, 4, 0, 0},
            {0, 4, 4, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {5, 5, 0, 0},
            {0, 5, 5, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 6, 0, 0},
            {6, 6, 6, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, 0, 7, 0},
            {0, 7, 7, 7},
            {0, 0, 0, 0}
        }
    };

    blockType = rand() % 7;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[i][j] = blocks[blockType][i][j];
        }
    }
    blockX = WIDTH / 2 - 2;
    blockY = 0;
}

void drawBoard() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 0) {
                cout << "  ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

bool moveBlock(int dx, int dy) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (block[i][j] != 0) {
                int x = blockX + j + dx;
                int y = blockY + i + dy;
                if (x < 0 || x >= WIDTH || y >= HEIGHT) {
                    return false;
                }
                if (y >= 0 && board[y][x] != 0) {
                    return false;
                }
            }
        }
    }
    blockX += dx;
    blockY += dy;
    return true;
}

void rotateBlock() {
    int temp[BLOCK_SIZE][BLOCK_SIZE] = {0};
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            temp[i][j] = block[i][j];
        }
    }
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[i][j] = temp[BLOCK_SIZE - j - 1][i];
        }
    }
    if (blockX < 0) {
        blockX = 0;
    } else if (blockX + BLOCK_SIZE > WIDTH) {
        blockX = WIDTH - BLOCK_SIZE;
    }
    if (blockY + BLOCK_SIZE > HEIGHT) {
        initBlock();
        drawBoard();
    }
}

int main() {
    srand(time(NULL));
    initBlock();
    while (true) {
        drawBoard();
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
                case 'a':
                    moveBlock(-1, 0);
                    break;
                case 'd':
                    moveBlock(1, 0);
                    break;
                case 's':
                    moveBlock(0, 1);
                    break;
                case 'w':
                    rotateBlock();
                    break;
                case ' ':
                    while (moveBlock(0, 1)) {}
                    break;
            }
        }
        if (!moveBlock(0, 1)) {
            for (int i = 0; i < BLOCK_SIZE; i++) {
                for (int j = 0; j < BLOCK_SIZE; j++) {
                    if (block[i][j] != 0) {
                        int x = blockX + j;
                        int y = blockY + i;
                        board[y][x] = blockType + 1;
                    }
                }
            }
            initBlock();
        }
        Sleep(100);
    }
    return 0;
}
