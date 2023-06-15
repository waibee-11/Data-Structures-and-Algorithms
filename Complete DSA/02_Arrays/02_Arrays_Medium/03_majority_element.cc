/*
Given an array nums of size n, return the majority element.
*/

/*
- Use the MOORE'S VOTING ALGORITHM:
    - let el be the majority element and ct be the no. of times it occurs
    - initially let el be nums[0] and ct = 1
    - if we encounter el, we increment ct by 1, else we decrement by 1
    - if ct reaches 0, we can conclude that we haven't found a majority element in the sub array so far
    - we start again and set el as the next element and ct = 0
*/

#include <vector>
using namespace std;
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int el = nums[0];
    int ct = 1;
    for (int i = 1; i < n - 1; i++){
        if (nums[i] == el){
            ct++;
        } else {
            ct--;
        }
        if (ct == 0) {
            el = nums[i+1];
            ct = 0;
        }
    }
    return el;
}

// TC: O(n)