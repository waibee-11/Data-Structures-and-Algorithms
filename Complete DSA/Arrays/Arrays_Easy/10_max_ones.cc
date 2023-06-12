/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/

/*
We use a max_ones element to track the maximum no. of consecutive 1's seen so far.
*/

#include <vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int max_1 = 0;
    int cur_1 = 0;
    for (int i = 0; i < n; i++){
        if (nums[i] != 1){
            max_1 = max(max_1, cur_1);
            cur_1 = 0;
        } else {
            cur_1 ++;
        }
    }
    max_1 = max(max_1, cur_1);
    return max_1;
}

// TC: O(n)