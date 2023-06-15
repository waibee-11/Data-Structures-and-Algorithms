/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/

/*
- We use an approach similar to n/2 majority element
- Since there can be 2 elements with n/3 majority, we track 2 elements
*/

#include <vector>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
    vector<int> sol;
    int n = nums.size();
    int ct1 = 0;
    int ct2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for (int i = 0; i < n; i++){
        if (ct1 == 0 && el2 != nums[i]){
            ct1 = 1;
            el1 = nums[i];
        }
        else if (ct2 == 0 && el1 != nums[i]){
            ct2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i]){
            ct1++;
        }
        else if (el2 == nums[i]){
            ct2++;
        }
        else {
            ct1--;
            ct2--;
        }
    }
    ct1 = 0, ct2 = 0;
    for (int i = 0; i < n; i++){
        if (nums[i] == el1) ct1++;
        if (nums[i] == el2) ct2++;
    }
    int gt3 = (int) (n / 3) + 1;
    if (ct1 >= gt3) sol.push_back(el1);
    if (ct2 >= gt3) sol.push_back(el2);
    return sol;
}

// TC: O(n)