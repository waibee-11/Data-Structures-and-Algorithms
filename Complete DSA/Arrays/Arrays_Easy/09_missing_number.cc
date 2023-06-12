/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/

/*
- Use the formula to find the sum of the first n natural numbers.
- Then subtract the sum of the elements of the array from the theoretical sum.
*/

#include <vector>
using namespace std;
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int theory_sum = n * (n + 1) / 2;
    int real_sum = 0;
    for (int i = 0; i < n; i++){
        real_sum += nums[i];
    }
    return theory_sum - real_sum;
}

// TC: O(n)