/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

/*
- We use binary search to find the optimum eating rate
- Minimum eating rate = 1 and maximum eating rate = max(piles)
*/

#include <vector>
using namespace std;
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int maxi = 0;
    for (int i = 0; i < n; i++){
        maxi = max(maxi, piles[i]);
    }
    int k = maxi;
    int low = 1;
    int high = maxi;
    while (low <= high){
        int mid = (low + high) / 2;
        long long int hours = 0;
        for (int i = 0; i < n; i++){
            hours += (piles[i]/mid + (piles[i] % mid != 0));
        }
        // cout << "mid = " << mid << " and hours = " << hours << endl; [debugging]
        if (hours <= h){
            k = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        // cout << k << endl; [for debugging]
    }
    return k;
}

// TC: O(log max(piles))