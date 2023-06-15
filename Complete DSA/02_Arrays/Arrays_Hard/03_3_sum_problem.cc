/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
*/

/*
- We convert this into a 2-sum problem.
- Choose one element and then find 2 other elements such their sum  is 0
- Do this for every element and you're done!
*/

#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> v;
    for (int i = 0; i < n; i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0){
                v.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (j < k && nums[j] == nums[j-1]) j++;
                k--;
                while (k > j && nums[k] == nums[k+1]) k--;
            } else if (sum > 0) {
                k--;
            } else {
                j++;
            }
        }
    }
    return v;
}

// TC: O(nlogn) + O(n^2)
//    [sorting]