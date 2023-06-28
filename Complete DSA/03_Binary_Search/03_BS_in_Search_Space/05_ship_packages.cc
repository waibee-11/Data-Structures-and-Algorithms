/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/

/*
We use binary search. The starting and ending points of the search space are the maximum element and the total weight (sum) of the array.

We check if a given weight would satisfy our contraints, by creating a function called 'satisfies'.
*/

#include <vector>
using namespace std;
bool satisfies(vector<int>& weights, int days, int mid){
    int sum = 0;
    int max_days = 0;
    // cout << "mid = " << mid << endl;
    for (int i = 0; i < weights.size(); i++){
        sum += weights[i];
        // cout << "sum = " << sum << endl;
        if (sum > mid){
            max_days += 1;
            sum = weights[i];
            // cout << "MD = " << max_days << endl;
        }
    }
    max_days++;
    // cout << "mid = " << mid << " "; <--for debugging-->
    // cout << "max_days = " << max_days << endl; <--for debugging-->
    return (max_days <= days);
}

int shipWithinDays(vector<int>& weights, int days) {
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < weights.size(); i++){
        sum += weights[i];
        maxi = max(maxi, weights[i]);
    }
    int low = maxi;
    int high = sum;
    int min_weight = sum;
    while (low <= high){
        int mid = (low + high) / 2;
        if (satisfies(weights, days, mid)){
            min_weight = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return min_weight;
}

// TC: O(n) + O(nlogn) ~ O(nlogn)