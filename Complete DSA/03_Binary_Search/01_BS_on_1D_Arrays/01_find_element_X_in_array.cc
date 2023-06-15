/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
*/

/*
- We use Binary Search (obviously!)
    - We keep reducing our search area by half
*/

#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (nums[mid] == target){
            return mid;
        } else if (nums[mid] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// TC: O(log n) since our search array is halved in every iteration