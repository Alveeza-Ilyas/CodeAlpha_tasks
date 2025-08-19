#include <iostream>
using namespace std;

const int N = 9;

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
            if (col == 2 || col == 5) cout << "| ";
        }
        cout << endl;
        if (row == 2 || row == 5) {
            cout << "------+-------+------" << endl;
        }
    }
}

// Function to check if a number can be placed in the given cell
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if 'num' is not already placed in current row, column and 3x3 box
    for (int x = 0; x < N; x++) {
        // Check row
        if (grid[row][x] == num) return false;
        // Check column
        if (grid[x][col] == num) return false;
    }

    // Check 3x3 box
    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[boxStartRow + i][boxStartCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // Find an empty cell
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }

    // If no empty cell left, puzzle is solved
    if (!isEmpty) return true;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Assign the number if it's safe
            grid[row][col] = num;

            // Recursively solve the rest of the puzzle
            if (solveSudoku(grid)) {
                return true;
            }

            // If recursion fails, backtrack and try next number
            grid[row][col] = 0;
        }
    }

    // Trigger backtracking
    return false;
}

int main() {
    // 0 represents empty cells
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku:" << endl;
    printGrid(grid);
    cout << "\nSolving...\n" << endl;

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku." << endl;
    }

    return 0;
}