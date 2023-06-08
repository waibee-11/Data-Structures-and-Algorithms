/*Problem Statement: Given an array, we have to find the largest element in the array.*/

/*No need for any explanation here. This problem is extremely straightforward.*/

#include <vector>
using namespace std;
int largest(vector<int> &arr, int n){
    int maximum = arr[0];
    for (int i = 1; i < n; i++){
        maximum = max(maximum, arr[i]);
    }
    return maximum;
}
// TC: O(n)