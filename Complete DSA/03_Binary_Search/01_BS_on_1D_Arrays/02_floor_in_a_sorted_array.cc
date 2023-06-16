/*
Given a sorted array arr and an element X, find the floor of X.

Floor of a X is defined as the greatest element less than or equal to X.
*/

/*
- Use Binary Search
    - Store arr[mid] into floor only while moving right
*/

#include <vector>
using namespace std;
int floorSearch(vector<int> & arr, int X, int N){
    int low = 0;
    int high = N;
    int floor = -1;
    while (low <= high){
        int mid = (low + high)/2;
        if (arr[mid] == X){
            floor = arr[mid];
            return floor;
        } else if (arr[mid] > X){
            high = mid - 1;
        } else {
            floor = arr[mid];
            low = mid + 1;
        }
    }
    return floor;
}

// TC: O(log n)