/* Problem Statement:
Give an array of integers, sort it in an increasing order using Bubble Sort.

Bubble Sort -> It involves continuously swapping adjacent elements such that larger elements get "bubbled" to the end of the array after every iteration.*/

#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n - i - 1; j++){ // since the last i elements will be sorted
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}