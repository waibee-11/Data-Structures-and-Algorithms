/*
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
*/

/*
- We can observe that the minimum element will always lie in the unsorted half
- We have 2 cases, wherein the unsorted half can be on either side of mid
- So, we eliminate the sorted half every time and we end up getting the min
*/

#include <vector>
using namespace std;
int findMin(vector<int>& nums) {
    int high = nums.size() - 1;
    int low = 0;
    int mid = 0;
    int mini = INT_MAX;
    while (low <= high){
        mid = (low + high) / 2;
        mini = min(mini, nums[mid]);
        // cout << "mid = " << mid << endl; [for debugging]
        if (nums[low] <= nums[mid] && nums[high] >= nums[mid]){
            high = mid - 1;
        }
        else if (nums[low] > nums[mid]) high = mid - 1;
        else low = mid + 1;
    }
    // cout << "mid = " << mid << endl; [for debugging]
    return mini;
}

// TC: O(log n)