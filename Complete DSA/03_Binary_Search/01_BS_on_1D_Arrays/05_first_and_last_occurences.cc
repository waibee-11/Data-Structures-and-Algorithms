/*
Given a sorted array of N integers, write a program to find the index of the first and last occurrence of the target key. If the target is not found then return -1.
*/

/*
- We use lower and upper bound code to solve this question
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

// TC: O(log n)