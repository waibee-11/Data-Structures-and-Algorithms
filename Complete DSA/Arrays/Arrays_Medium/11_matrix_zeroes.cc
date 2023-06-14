/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
*/

/*
- We create 2 arrays (row and col) to indicate whether a particular row or column is to be made 0
- We then traverse through the matrix and if we encounter a 0, we make it's row and column 0 by setting appropriate elements in the row and col array 0
- We then re-traverse through the entire matrix and set elements 0 according to the row and col arrays.
*/

#include <vector>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    vector<int> row(rows, 0);
    vector<int> col(columns, 0);

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

// TC: O(n^2) since we are traversing through the matrix
// SC: O(n+m) since we are making an n-sized and an m-sized array