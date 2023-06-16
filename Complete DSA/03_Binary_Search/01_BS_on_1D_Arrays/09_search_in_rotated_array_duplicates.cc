/*
Given a sorted rotated array with duplicates, return if an element is present in the array.
*/

/*
- Most of the code is the same as the previous question.
- The previous code breaks when arr[low] == arr[mid] == arr[high]
    - So, whenever such a case occurs, we trim down the search space by reducing high and increasing low by 1
*/

#include <vector>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int>&arr, int key) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] == key) return true;
        if (arr[mid] == arr[low] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }
        // left sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= key && key <= arr[mid]) high = mid - 1;
            else low = mid + 1;
        }
        // right sorted
        else {
            if (arr[mid] <= key && key <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return false;
}

// TC: O(log n)