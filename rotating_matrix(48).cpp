#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); 

        //Transpose matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { 
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
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
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    solution.rotate(matrix);
    cout << "Matrix after rotation:" << endl;
    printMatrix(matrix);

    return 0;
}