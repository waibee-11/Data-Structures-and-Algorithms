/*
Given an array arr and element x, return its lower bound
*/

/*
- Similar approach to the upper bound question, with minor tweaks
*/

#include <vector>
using namespace std;
int lowerBound(vector<int> arr, int n, int x) {
	int low = 0;
	int high = n - 1;
	int index = n;
	while (low <= high){
		int mid = (low + high) / 2;
		if (arr[mid] == x) return mid;
		else if (arr[mid] > x){
			index = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return index;
}

// TC: O(log n)