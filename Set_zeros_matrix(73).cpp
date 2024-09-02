#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns

        vector<int> row(n, 0);    // Row markers
        vector<int> col(m, 0);    // Column markers

        // First pass: Mark the rows and columns that need to be zeroed
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;  // Mark the row
                    col[j] = 1;  // Mark the column
                }
            }
        }

        // Second pass: Update the matrix based on row and col markers
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0; // Set the cell to zero
                }
            }
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    solution.setZeroes(matrix);

    cout << "Matrix after setZeroes:" << endl;
    printMatrix(matrix);

    return 0;
}