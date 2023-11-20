#include <stdio.h>
#include <stdbool.h>
#define N 20 
int board[N][N];
void printBoard(int n) {
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 printf("%c ", board[i][j] ? 'Q' : '.');
 
}
 printf("
\n");
 
}
}
bool isSafe(int row, int col, int n) {
 int i, j;
 for (i = 0; i < col; i++) {
 if (board[row][i]) {
 return false;
 
}
 
}
 for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
 if (board[i][j]) {
 return false;
 
}
 
}
 for (i = row, j = col; i < n && j >= 0; i++, j--) {
 if (board[i][j]) {
 return false;
 }
 }
 return true;
}
bool solveNQueens(int col, int n) {
 if (col >= n) {
 return true; // All queens are placed successfully
 }
 for (int i = 0; i < n; i++) {
 if (isSafe(i, col, n)) {
 board[i][col] = 1;
 if (solveNQueens(col + 1, n)) {
 return true;
 }
 board[i][col] = 0; 
 }
 }
 return false; 
}
int main() {
 int n;
 printf("-------------------------------------------------\n");
 printf("Enter the number of queens: ");
 scanf("%d", &n);
 if (n < 4) {
 printf("No solution exists for less than 4 queens.\n");
 return 1;
 }
 if (n > N) {
 printf("Board size is too large.\n");
 return 1;
 }
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 board[i][j] = 0;
 }
 }
 if (solveNQueens(0, n)) {
 printf("Solution exists:\n");
 printBoard(n);
 } else {
 printf("No solution exists.\n");
 }
 printf("\n-------------------------------------------------\n");
 return 0;
}
