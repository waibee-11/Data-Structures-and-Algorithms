/*
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
    - 0 <= i < j < nums.length and
    - nums[i] > 2 * nums[j].
*/

/*
- We use a similar approach to count_inversions (previous problem)
*/

#include <vector>
using namespace std;
int ct = 0;
void merge(vector<int> & arr, int start, int mid, int end){
    int i = start;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= end){
        if (arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end){
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = start; i <= end; i++){
        arr[i] = temp[i - start];
    }
}
void countPairs(vector<int> &arr, int low, int mid, int high){
    int right = mid + 1;
    for (int i = low; i < mid+1; i++){
        while (right <= high && arr[i] > 2*arr[right]) right++;
        ct += (right - (mid + 1));
    }
}

// mS breaks the array into 2 halves and then calls the merge function to merge them
void mS(vector<int> & arr, int start, int end){
    if (start == end){
        return;
    }
    int mid = (start + end) / 2;
    mS(arr, start, mid);
    mS(arr, mid + 1, end);
    countPairs(arr, start, mid, end);
    merge(arr, start, mid, end);
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    mS(nums, 0, n - 1);
    return ct;
}

// TC: O(nlogn)