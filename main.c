#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char currentplayer;
int player1wins = 0, player2wins = 0;

void loadgamedata() {
    FILE *file = fopen("tic_tac_toe_data.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d %d", &player1wins, &player2wins);
        fclose(file);
    }
}

void savegamedata() {
    FILE *file = fopen("tic_tac_toe_data.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d\t%d\n", player1wins, player2wins);
        fclose(file);
    }
}

void initializeboard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentplayer = 'X';
}

void displayboard() {
    FILE *boardfile = fopen("tic_tac_toe_board.txt", "w");
    if (boardfile == NULL) {
        printf("Error creating board file.\n");
        return;
    }
    fprintf(boardfile, "Game Analysis:");
    fprintf(boardfile, "\n");
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            fprintf(boardfile, " %c ", board[i][j]);

            if (j < 2) {
                printf("|");
                fprintf(boardfile, "|");
            }
        }
        printf("\n");
        fprintf(boardfile, "\n");

        if (i < 2) {
            printf("-----------");
            fprintf(boardfile, "-----------");
        }
        printf("\n");
        fprintf(boardfile, "\n");
    }
    fclose(boardfile);
}

int checkwin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1;
    return 0;
}

int checkdraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void switchplayer() {
    currentplayer = (currentplayer == 'X') ? 'O' : 'X';
}

int main() {
    int row, col;
    loadgamedata();
    initializeboard();

    while (1) {
        displayboard();
        printf("Player %c, enter row (0-2) and column (0-2): ", currentplayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = currentplayer;

        if (checkwin()) {
            displayboard();
            printf("Player %c wins!\n", currentplayer);
            if (currentplayer == 'X') player1wins++;
            else player2wins++;
            savegamedata();
            break;
        }

        if (checkdraw()) {
            displayboard();
            printf("It's a draw!\n");
            break;
        }

        switchplayer();
    }

    printf("Player 1 Wins: %d\n", player1wins);
    printf("Player 2 Wins: %d\n", player2wins);

    return 0;
}
