/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

/*
- We can use a hashmap to store every element's index.
- We then traverse across the array and check if the map contains target - arr[i]
- If we find it, then we have found our answer. Else, we add arr[i] to the map and continue.
*/

#include <vector>
#include <map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> sol;
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        if (mp[target - nums[i]] && mp[target - nums[i]] != i + 1){
            sol.push_back(i);
            sol.push_back(mp[target - nums[i]] - 1);
            break;
        }
        mp[nums[i]] += i + 1;
    }
    return sol;
}

// TC: O(n)
// SC: O(n) since we may need to all but 1 element in the map