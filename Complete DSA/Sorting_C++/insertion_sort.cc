/* Problem Statement:
Give an array of integers, sort it in an increasing order using Insertion Sort.

Insertion Sort -> It involves inserting every element into its correct position by comparing with elements to its left.*/

#include <vector>
using namespace std;
void insertionSort(int n, vector<int> &arr){
    for (int i = 0; i < n; i++){
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]){
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}