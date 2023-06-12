/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/

/*
- We use a 2-pointer method here. Initialize i = 0 and j = 1. Then:
    - we want i to be at a 0
    - we want j to be at a non-0
    - we want i < j (that is 0 should be before non-0)
    - if all the conditions are satisfied, we swap the elements at i and j
    - we stop the loop once j reaches the end of the array
*/

#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = 1;
    while (j < n && i < n){
        if (j == i) j++;
        else if (nums[j] == 0){
            j++;
        }
        else if (nums[i] != 0){
            i++;
        }
        else if (j < n && i < j && nums[i] == 0 && nums[j] != 0){
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
    }
}

// TC: O(n) since we are traversing through the array only once