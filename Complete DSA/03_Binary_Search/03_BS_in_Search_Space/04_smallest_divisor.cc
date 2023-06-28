/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
*/

/*
We use binary search. The starting and ending points of the search space are 1 and the maximum element of the array.

We check if a given number would satisfy our contraints, by creating a function called 'satisfies'.
*/

#include <vector>
using namespace std;
bool satisfies(vector<int>& nums, int threshold, int mid){
    int sum = 0;
    for (int i = 0; i < nums.size(); i++){
        sum += (nums[i] + (mid - 1)) / mid;
    }
    return (sum <= threshold);
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++){
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
    }
    int low = 1;
    int high = maxi;
    int req = 1;
    while (low <= high){
        int mid = (low + high) / 2;
        // cout << low << " " << mid << " " << high << endl; [for debugging]
        if (satisfies(nums, threshold, mid)){
            req = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return req;
}

// TC: O(n) + O(nlogn) ~ O(nlogn)