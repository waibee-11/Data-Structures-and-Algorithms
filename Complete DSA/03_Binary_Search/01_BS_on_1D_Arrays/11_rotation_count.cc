/*
Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. Find the value of K.
*/

/*
- We use the previous question's code and it is pretty straightforward
*/

#include <vector>
using namespace std;
int findMin(vector<int> nums) {
    int high = nums.size() - 1;
    int low = 0;
    int mid = 0;
    int mini = INT_MAX;
    while (low <= high){
        mid = (low + high) / 2;
        mini = min(mini, nums[mid]);
        // cout << "mid = " << mid << endl;
        if (nums[low] <= nums[mid] && nums[high] >= nums[mid]){
            high = mid - 1;
        }
        else if (nums[low] > nums[mid]) high = mid - 1;
        else low = mid + 1;
    }
    // cout << "mid = " << mid << endl;
    return mini;
}

int findKRotation(int arr[], int n) {
    vector<int> nums; // added this vector because gfg uses only arrays
    for (int i = 0; i < n; i++) nums.push_back(arr[i]);
    int mini = findMin(nums);
    return (find(nums.begin(), nums.end(), mini) - nums.begin());
}

// TC: O(log n)