/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
*/

/*
- We make use of the fact that the matrix is sorted row-wise and column-wise.
- Start at [0, n] and then move horizontally for elements smaller and vertically for elements bigger.
*/

#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = m - 1;
    while (i < n && j > -1){
        // cout << matrix[i][j] << endl; [for debugging]
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] < target) i++;
        else j--;
    }
    return false;
}

// TC: O(log m*n)