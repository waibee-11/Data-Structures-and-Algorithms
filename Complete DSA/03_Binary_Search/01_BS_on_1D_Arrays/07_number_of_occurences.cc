/*
Given an array arr and element x, return the number of times x is in arr
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

int count(vector<int>& arr, int n, int x) {
	pair<int, int> first_last = firstAndLastPosition(arr, n, x);
	if (first_last.first == -1 && first_last.second == -1) return 0;
	return first_last.second - first_last.first + 1;
}

// TC: O(log n)