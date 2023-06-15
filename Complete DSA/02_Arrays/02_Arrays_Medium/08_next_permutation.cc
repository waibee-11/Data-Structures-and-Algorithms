/*
Given an array of integers nums, find the next permutation of nums.

For example, given [2,4,1,7,5,0], the answer would be [2,4,5,0,1,7]
*/

/*
- We use the NEXT PERMUTATION ALGORITHM:
    - Find the pivot by looking for the first element such that arr[i] < arr[i + 1]
    - Find the right-most successor the pivot.
    - Now swap the successor and the pivot.
    - Finally, reverse the sub array arr[pivot + 1] to arr[end]
*/

#include <vector>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pt1 = INT_MIN;
    for (int i = n - 1; i > 0; i--){
        if (nums[i] > nums[i-1]){
            pt1 = i - 1;
            break;
        }
    }
    if (pt1 == INT_MIN){
        reverse(nums.begin(), nums.end());
        return;
    }
    int pt2;
    for (int i = n - 1; i > pt1; i--){
        if (nums[i] > nums[pt1]){
            pt2 = i;
            break;
        }
    }
    swap(nums[pt1], nums[pt2]);
    reverse(nums.begin() + pt1 + 1, nums.end());
}

// TC: O(n) if the pivot is the first element