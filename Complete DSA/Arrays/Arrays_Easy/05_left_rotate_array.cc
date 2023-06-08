/*
Given an array arr[] of size N and an integer K, the task is to left rotate the array K indexes.
*/

/*
- Here we make use of a mathematical result (BA^rev) = (A)^rev(B)^rev
- Consider A to be the first k elements and B to be the next N-K elements
- By reversing A, then reversing B and then reversing AB, we essentially get BA, which is what we need.
*/

#include <algorithm>
using namespace std;
void leftRotate(int arr[], int k, int n) {
    k = (k % n);
    if (k == n) return;
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);
}