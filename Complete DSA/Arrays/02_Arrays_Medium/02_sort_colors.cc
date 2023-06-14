/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
*/

/*
- Use the Dutch National Flag algorithm
    - Consider 0 0 0 0 1 1 1 1 [Our Array] 2 2 2 2
    - All 0's are from start to low - 1
    - All 1's are from low to mid - 1
    - Our array is from mid to high
    - All 2's are from high + 1 to end
    - We analyze elements at arr[mid]
        - if arr[mid] is 1, we simply increment mid as it matches our pattern above
        - if arr[mid] is 0, we swap it with low and increment low and mid
        - if arr[mid] is 2, we swap it with high and decrement high
*/

#include <vector>
using namespace std;
void sortColors(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid <= high){
        if (nums[mid] == 0){
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        } else if (nums[mid] == 1){
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// TC: O(n)