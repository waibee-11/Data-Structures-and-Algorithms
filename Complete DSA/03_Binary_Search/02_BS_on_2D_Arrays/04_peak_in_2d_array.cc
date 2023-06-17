/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
*/

/*
- We use a similar logic to finding peak in 1d array
- Use a max function to find the max element in a row
- Compare it with elements above and below it and eliminate the appropriate half
*/

#include <vector>
using namespace std;
int maxRow(vector<int>& nums) {
    int n = nums.size();
    int max_index = 0;
    for (int i = 1; i < n; i++){
        if (nums[i] > nums[max_index]){
            max_index = i;
        }
    }
    return max_index;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int low_row = 0;
    int high_row = n - 1;
    while (low_row <= high_row){
        int mid_row = (low_row + high_row) / 2;
        int mid_index = maxRow(mat[mid_row]);
        if (mid_row == 0){
            if (mat[mid_row][mid_index] > mat[mid_row+1][mid_index]) return {mid_row, mid_index};
            else low_row = mid_row+1;
        } else if (mid_row == n-1){
            if (mat[mid_row][mid_index] > mat[mid_row-1][mid_index]) return {mid_row, mid_index};
            else high_row = mid_row-1;
        } else {
            if (mat[mid_row][mid_index] > mat[mid_row+1][mid_index] && 
                mat[mid_row][mid_index] > mat[mid_row-1][mid_index]) return {mid_row, mid_index};
            else if (mat[mid_row][mid_index] < mat[mid_row+1][mid_index]) low_row = mid_row + 1;
            else if (mat[mid_row][mid_index] < mat[mid_row-1][mid_index]) high_row = mid_row - 1;
        }
    }
    return {-1,-1};
}

// TC: O(m*log(n))