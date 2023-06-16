/*
Given a sorted rotated array, find the index of a given element
*/

/*
- We use Binary Search, but we need to identify the sorted half and search in that
*/

#include <vector>
using namespace std;
int search(vector<int>& arr, int n, int k)
{
    int low = 0;
    int high = n;
    while (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] == k) return mid;
        // left sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) high = mid - 1;
            else low = mid + 1;
        }
        // right sorted
        else {
            if (arr[mid] <= k && k <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

// TC: O(log n) since we are virtually doing a Binary Search only