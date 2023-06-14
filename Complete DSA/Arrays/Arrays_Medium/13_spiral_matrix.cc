/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example: For the matrix [[1,2,3],[4,5,6],[7,8,9]], spiral order is [1,2,3,6,9,8,7,4,5]
*/

/*
- Create a helper function that does for a matrix once.
- Then use recursion to call that helper function for smaller matrices
*/

#include <vector>
using namespace std;
void spiral_helper(vector<vector<int>>& matrix, int b, int m, int n, vector<int> & spiral){
    if (0 >= n) return;
    for (int i = 0; i < n; i++){
        spiral.push_back(matrix[b][i+b]);
    }
    if (1 >= m) return;
    for (int i = 1; i < m; i++){
        spiral.push_back(matrix[i+b][n-1+b]);
    }
    if (n-2 <= -1) return;
    for (int i = n-2; i > -1; i--){
        spiral.push_back(matrix[m-1+b][i+b]);
    }
    if (m-2 <= 0) return;
    for (int i = m-2; i > 0; i--){
        spiral.push_back(matrix[i+b][b]);
    }
    spiral_helper(matrix, b+1, m-2, n-2, spiral);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> spiral;
    if (m == 1){
        for (int i = 0; i < n; i++){
            spiral.push_back(matrix[0][i]);
        }
    } else if (n == 1){
        for (int i = 0; i < m; i++){
            spiral.push_back(matrix[i][0]);
        }
    } else {
        spiral_helper(matrix, 0, m, n, spiral);
    }
    return spiral;
}

// TC: O(n^2) since we are traversing through the matrix once