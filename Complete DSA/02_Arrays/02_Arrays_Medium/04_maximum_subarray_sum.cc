/*
Given an integer array nums, find the sub array with the largest sum, and return its sum.
*/

/*
- We use the KADANE'S ALGORITHM:
    - we keep track of the sum from the start of the array
    - anytime the sum becomes negative, we reset it to 0
    - we also keep track of the maximum value of the sum, which is our answer
*/

#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int max_sum = nums[0];
    int sum = nums[0];
    for (int i = 1; i < n; i++){
        if (sum < 0){
            sum = 0;
        }
        sum += nums[i];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}