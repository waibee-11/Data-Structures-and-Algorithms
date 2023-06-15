/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
*/

/*
- By observation, we can develop the following algorithm:
    - Convert the matrix into its transpose
        - This can be done by swapping the row and column for every element
    - Now, we reverse elements in every row (reversing columns)
    - We get our answer!
*/

#include <vector>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// TC: O(n^2)