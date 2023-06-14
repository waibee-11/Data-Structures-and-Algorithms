/*
Given an array, find maximum sum of smallest and second smallest elements chosen from all possible sub-arrays.
*/

/*
- We find sums of all consecutive elements and return the highest one.
*/

#include <iostream>
using namespace std;
long long pairWithMaxSum(long long arr[], long long N){
    long long maxi = INT_MIN;
    for (int i = 0; i < N - 1; i++){
        maxi = max(maxi, arr[i] + arr[i+1]);
    }
    return maxi;
}

// TC: O(n)