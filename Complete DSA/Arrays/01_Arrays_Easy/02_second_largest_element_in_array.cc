/*Given an array Arr of size N, print second largest distinct element from an array.*/

/*Similar approach to the previous question. Here, we keep track of 2 variables and update them appropriately.*/

#include <vector>
using namespace std;
int print2largest(int arr[], int n) {
	int maximum = arr[0];
	int sec_maximum = INT_MIN;
	for (int i = 1; i < n; i++){
		if (arr[i] > maximum){
			sec_maximum = maximum;
			maximum = arr[i];
		} else if (arr[i] > sec_maximum && arr[i] != maximum){
			sec_maximum = arr[i];
		}
	}
	if (sec_maximum == INT_MIN) return -1;
	return sec_maximum;
}

// TC: O(n)