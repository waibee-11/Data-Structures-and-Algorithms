/*
Given an array arr, and an element m, find the correct index to insert m in arr.
If m already exists in arr, return its index.
*/

/*
- This is also a variation of previous questions.
*/

#include <vector>
using namespace std;
int searchInsert(vector<int>& arr, int m){
	int n = arr.size();
	int low = 0;
	int high = n;
	int index = n;
	while (low <= high){
		int mid = (low + high) / 2;
		if (arr[mid] == m) return mid;
		else if (arr[mid] > m) {
			index = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
    return index;
}

// TC: O(log n)