#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void displayGrid(char grid[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", grid[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') return 1;
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') return 1;
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') return 1;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') return 1;
    return 0;
}

int isDraw(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void playerMove(char grid[SIZE][SIZE], char player) {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && grid[row - 1][col - 1] == ' ') {
            grid[row - 1][col - 1] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void aiMove(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == ' ') {
                grid[i][j] = 'O';
                return;
            }
        }
    }
}

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int mode;
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Choose mode:\n");
    printf("1. Two-player mode\n");
    printf("2. Single-player mode (vs AI)\n");
    printf("Enter your choice: ");
    scanf("%d", &mode);

    char currentPlayer = 'X';
    while (1) {
        displayGrid(grid);
        if (mode == 1 || (mode == 2 && currentPlayer == 'X')) {
            playerMove(grid, currentPlayer);
        } else if (mode == 2 && currentPlayer == 'O') {
            aiMove(grid);
        }

        if (checkWin(grid)) {
            displayGrid(grid);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isDraw(grid)) {
            displayGrid(grid);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
