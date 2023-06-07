/* Problem Statement:
Give an array of integers, sort it in an increasing order using Merge Sort.

Merge Sort -> This is a recursive sorting technique. It involves breaking up the array into 2 sub-arrays and sorting them by breaking them into 2 sub-arrays (4 each) and so on. We keep breaking arrays until we get a singular array. We then re-join/merge the individual arrays into a single array in a sorted manner. In short, Merge sort involves breaking the array to singular arrays, and then merging each of the singular arrays to get our original array sorted. */

#include <vector>
using namespace std;

// merge function merges arr[start : mid] and arr[mid+1 : end] in a sorted manner
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

// mS breaks the array into 2 halves and then calls the merge function to merge them
void mS(vector<int> & arr, int start, int end){
    if (start == end){
        return;
    }
    int mid = (start + end) / 2;
    mS(arr, start, mid);
    mS(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

// wrapper function that calls mS
void mergeSort(vector < int > & arr, int n) {
    mS(arr, 0, n - 1);
}