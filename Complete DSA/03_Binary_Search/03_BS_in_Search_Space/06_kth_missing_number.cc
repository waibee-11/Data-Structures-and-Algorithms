/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
*/

/*
On observation we see that, the number of missing numbers before an index is equal to arr[i] - (i+1). So, we find the 2 indexes between which the kth missing number is.

Next, we derive the formula to find the kth missing number which is low + k.
*/

#include <vector>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    if (arr[n-1] - n == 0) return arr[n-1] + k;
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] - (mid + 1) < k) low = mid + 1;
        else {
            high = mid - 1;
        }
    }
    return low + k;
}

// TC: O(logn)