/*
Given an array arr[] sorted in ascending order of size N and an integer K. Check if K is present in the array or not. Return 1 or -1 appropriately.
*/

/*
No need for any explanation here. We only need 1 for loop.
*/

using namespace std;
int searchInSorted(int arr[], int N, int K) 
{ 
    for (int i = 0; i < N; i++){
        if (arr[i] == K){
            return 1;
        }
    }
    return -1;
}

// TC: O(n)