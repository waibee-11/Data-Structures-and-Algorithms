/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.
*/

/*
- This question is similar to the previous question.
- Again, the focus is to design the sub_arr function.
- After that, it is a simple Binary search with low = max_arr and high = sum_arr
*/

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int sub_arr(vector<int>& nums, int min_sum){
    int ct = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if (sum > min_sum){
            ct++;
            sum = nums[i];
        }
    }
    return ct;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    while (low <= high){
        int mid = (low + high) / 2;
        int subarrays = sub_arr(nums, mid);
        if (subarrays > k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

// TC: O(n) + O(nlogn) ~ O(nlogn)