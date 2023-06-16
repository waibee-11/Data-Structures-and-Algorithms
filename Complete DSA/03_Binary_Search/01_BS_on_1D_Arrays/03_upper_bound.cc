/*
Give an array arr and an element x, find the upper bound of x

Upper bound of x is defined as the first element greater than x
*/

/*
- Use binary search
- Similar approach to the previous question with slight tweaks
*/

#include <vector>
using namespace std;
int upperBound(vector<int> &arr, int x, int n){
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

// TC: O(log n)