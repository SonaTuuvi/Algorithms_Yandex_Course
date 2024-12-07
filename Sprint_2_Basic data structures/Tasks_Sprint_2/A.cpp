/*
Description:
1. Purpose: This program reads a rectangular matrix, transposes it, and prints the transposed matrix. 
   - Transposing a matrix involves swapping its rows with columns.

2. Steps:
   - The dimensions `n` (number of rows) and `m` (number of columns) of the matrix are read.
   - The original matrix is stored in a 2D vector `matrix`.
   - A separate 2D vector `transposed` is initialized to store the transposed matrix.
   - Using nested loops, the program reads the elements of the input matrix into `matrix`.
   - Another nested loop transposes the matrix by assigning `matrix[i][j]` to `transposed[j][i]`.
   - Finally, the `transposed` matrix is printed, with each row on a new line and elements separated by spaces.

3. Key Features:
   - Vector of Vectors: A 2D `vector` is used to store both the original and transposed matrices dynamically, based on input dimensions.
   - Nested Loops: Used for both reading input and performing the transpose.
   - Transpose Logic: The element at row `i` and column `j` of the original matrix becomes the element at row `j` and column `i` in the transposed matrix.

4. Output Format:
   - Each row of the transposed matrix is printed on a new line.
   - Elements in a row are separated by spaces.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Reading the dimensions of the matrix
    int n, m;
    cin >> n >> m;

    // Initializing the original matrix and the transposed matrix
    vector<vector<int>> matrix(n, vector<int>(m));
    vector<vector<int>> transposed(m, vector<int>(n));

    // Reading elements of the original matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Transposing the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Printing the transposed matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << transposed[i][j];
            if (j < n - 1) {
                cout << " "; // Separate elements with spaces
            }
        }
        cout << endl; // Move to a new line after each row
    }

    return 0;
}
