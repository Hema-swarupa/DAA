#include <stdio.h>
#define MAX 20
int count = 0;

void printBoard(int board[MAX][MAX], int N) {
    printf("Solution %d:\n", ++count);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf(board[i][j] ? "Q " : ". ");
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[MAX][MAX], int row, int col, int N) {
    for(int i = 0; i < row; i++)
        if(board[i][col]) return 0;
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if(board[i][j]) return 0;
    for(int i = row-1, j = col+1; i >= 0 && j < N; i--, j++)
        if(board[i][j]) return 0;
    return 1;
}
void solve(int board[MAX][MAX], int row, int N) {
    if(row == N) {
        printBoard(board, N);
        return;
    }

    for(int col = 0; col < N; col++) {
        if(isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solve(board, row + 1, N);
            board[row][col] = 0;
        }
    }
}
int main() {
    int N;
    scanf("%d", &N);
    int board[MAX][MAX] = {0};
    solve(board, 0, N);
    printf("Total solutions = %d\n", count);
    return 0;
}