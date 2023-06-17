/*
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.
*/

/*
- We use the code for the first sighting of 1.
- Since the row is sorted, all the subsequent elements are going to be 1's
- We find the maximum number of 1's by keeping a max_one tracker
*/

#include <vector>
using namespace std;
int upperBound(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n;
    int index = n;
    while (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] <= x){
            low = mid + 1;
        } else {
            index = mid;
            high = mid - 1;
        }
    }	
    return index;
}

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n;
    int index = n;
    while (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] >= x){
            index = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return index;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = lowerBound(arr, n, k);
    // cout << "first = " << first << " and arr[first] = " << arr[first] << endl;
    if (first == n || arr[first] != k) return {-1, -1};
    else return {first, upperBound(arr, n, k) - 1};
}

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int max_1 = 0;
    int row_num = -1;
    for (int i = 0; i < n; i++){
        int ones = m - firstAndLastPosition(arr[i], m, 1).first;
        if (ones > m) continue;
        if (ones > max_1) row_num = i;
        max_1 = max(max_1, ones);
    }
    return row_num;
}

// TC: O(log n)