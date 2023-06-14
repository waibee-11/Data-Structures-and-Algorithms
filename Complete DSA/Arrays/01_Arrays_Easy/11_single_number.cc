/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
*/

/*
- Use the following 2 facts:
    - n XOR n = 0
    - 0 XOR n = n
*/

#include <vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int xory = nums[0];
    for (int i = 1; i < n; i++){
        xory = xory ^ nums[i];
    }
    return xory;
}

// TC: O(n)