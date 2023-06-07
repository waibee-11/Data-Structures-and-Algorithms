/* Problem Statement:
Give an array of integers, sort it in an increasing order using Selection Sort.

Selection sort -> It involves selecting the smallest element in the array in every iteration and placing it in the front.*/

#include <iostream>
#include <vector>
using namespace std; 
void selectionSort(vector<int>& arr, int n)
{   
    for (int i = 0; i < n; i++){
        int min_index = i;
        for (int j = i; j < n; j++){ // finding the smallest element in [i + 1 : n]
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]); // swap to bring the smallest element in the front
    }
}
