/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
*/

/*
- We compare mid with its neighbour elements.
- If any one of its neighbour is greater, we choose that sub array.
- If mid is greater than both its neighbour elements, we have found a peak.
*/

#include <vector>
using namespace std;
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (mid > 0 && mid < n - 1 && nums[mid] > max(nums[mid-1], nums[mid+1])){
            return mid;
        } else if (mid > 0 && nums[mid-1] > nums[mid]) high = mid - 1;
        else if (mid < n-1 && nums[mid+1] > nums[mid]) low = mid + 1;
        else return mid;
    }
    return 1;
}