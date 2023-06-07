/* Problem Statement:
Give an array of integers, sort it in an increasing order using Quick Sort.

Quick Sort -> This is also a recursive sorting method. This involves finding a pivot and placing it in such a way that all the elements to its left and smaller than it, and all the elements to the right and larger than it. We then sort the left and right sub-arrays using the same method. */

#include <vector>
using namespace std;
int partition(vector<int> & arr, int low, int high){
    int i = low;
    int j = high;
    int pivot = low;

    while (i < j){
        while (arr[i] <= arr[pivot] && i <= high - 1){
            i++;
        }

        while (arr[j] > arr[pivot] && j >= low + 1){
            j--;
        }

        if (i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[pivot], arr[j]);
    return j;
}

void qS(vector<int> & arr, int low, int high){
    if (low < high){
        int p_index = partition(arr, low, high);
        qS(arr, low, p_index - 1);
        qS(arr, p_index + 1, high);
    }
}

vector<int> quickSort(vector<int> arr)
{
    qS(arr, 0, arr.size() - 1);
    return arr;
}