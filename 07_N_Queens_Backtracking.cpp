#include <iostream>
#include <cstdlib>

using namespace std;

int board[4][4] = {0};
int n = 4, total = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                if (j == col || abs(i-row) == abs(j-col)) {
                    return false;
                }
            }
        }
    }

    return true;
}

void printBoard() {
    total++;
    cout << "\nSolution " << total << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                cout << "Q ";
            }
        }
        else {
            cout << ". ";
        }

        cout << endl;
    }
}

void solve(int row) {
    if (row == n) {
        printBoard();
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solve(row + 1);
            board[row][col] = 0;
        }
    }
}

int main() {
    solve(0);
    cout << "\nTotal solutions = " << total << endl;
    return 0;
}
