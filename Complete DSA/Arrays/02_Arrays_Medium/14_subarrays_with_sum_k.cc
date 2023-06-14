/*
Given an array of integers nums and an integer k, return the total number of sub arrays whose sum equals to k.
*/

/*
- Use the prefix sum method
    - Let's say the prefix sum till index i is S
    - Your target is K
    - You look for prefix sums S - K (for indices before i)
*/

#include <vector>
#include <map>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    map<int, int> mp;
    mp[0] = 1;
    int preSum = 0;
    int ct = 0;
    for (int i = 0; i < n; i++){
        preSum += nums[i];
        int remove = preSum - k;
        ct += mp[remove];
        mp[preSum] += 1;
    }
    return ct;
}

// TC: O(n)
// SC: O(n)