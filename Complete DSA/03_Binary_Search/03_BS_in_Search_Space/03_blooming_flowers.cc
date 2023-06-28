/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/

/*
We use binary search. The starting and ending points of the search space are minimum and maximum elements of the array.

We check if a given number of days would satisfy our contraints, by creating a function called 'day_possible'.
*/

#include <vector>
using namespace std;
bool day_possible(vector<int> arr, int k, int m, int mid){
	int n = arr.size();
	int ct = 0;
	int noOB = 0; 
	for (int i = 0; i < n; i++){
		if (arr[i] <= mid) ct++;
		else{
			noOB += ct / k;
			ct = 0;
		}
	}
	noOB += ct / k;
	if (noOB >= m) return true;
	return false;
}

int roseGarden(vector<int> arr, int k, int m)
{
	int n = arr.size();
	int maxi = INT_MIN;
	int mini = INT_MAX;
	for (int i = 0; i < n; i++){
		maxi = max(maxi, arr[i]);
		mini = min(mini, arr[i]);
	}

	int low = mini;
	int high = maxi;
	int opt_day = -1;
	while (low <= high){
		int mid = (low + high) / 2;
		if (day_possible(arr, k, m, mid) == false) low = mid + 1;
		else{
			opt_day = mid;
			high = mid - 1;
		}
	}
	return opt_day;
}

// TC: O(n) + O(nlogn) ~ O(nlogn)