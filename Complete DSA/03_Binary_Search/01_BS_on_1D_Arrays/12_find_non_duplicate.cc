/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

/*
- Since the array is always going to be of odd length, we have to compare arr[mid] with the element before and after it
- If the half-array length is odd and if the arr[mid+1] == arr[mid], then the non-duplicate element is in the other half
- Similar for other cases as well
- If arr[mid] is not equal to either of its adjacent elements, it is the non-duplicate element
*/

#include <vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n-1] != nums[n-2]) return nums[n-1];
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
        else if (nums[mid] == nums[mid - 1]){
            if (mid % 2 == 1) low = mid + 1;
            else high = mid - 1;
        }
        else {
            if (mid % 2 == 1) high = mid - 1;
            else low = mid + 1;
        }
    }
    return -1;
}

// TC: O(log n)