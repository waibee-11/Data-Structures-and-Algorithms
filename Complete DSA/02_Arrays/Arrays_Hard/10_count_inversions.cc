/*
Given an array of integers. Find the Inversion Count in the array. 

Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
*/

/*
- We implement this using the merge sort algorithm
- Whenever, we find arr1[i] > arr2[j], we increment ct by 1
*/

#include <vector>
using namespace std;
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    int ct = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
            ct += mid - left + 1;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return ct;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int ct = 0;
    if (low >= high) return ct;
    int mid = (low + high) / 2 ;
    ct += mergeSort(arr, low, mid);  // left half
    ct += mergeSort(arr, mid + 1, high); // right half
    ct += merge(arr, low, mid, high);  // merging sorted halves
    return ct;
}

int numberOfInversions(vector<int> &a, int n) {
    return mergeSort(a, 0, n-1);
}

// TC: O(nlogn)