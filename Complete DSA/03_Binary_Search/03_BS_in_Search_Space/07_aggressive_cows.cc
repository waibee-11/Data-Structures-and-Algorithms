/*
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.
*/

/*
- We first sort the array. We want to only check the distances between consecutive elements.
- We start with min_dist = 1 and check if we can place at least k cows.
- We keep increasing min_dist by 1, until we reach a point where we cannot place k cows. We have found the maximum min_dist.
- We convert this to Binary Search. low = 1 and high = arr_max - arr_min.
*/

#include <vector>
using namespace std;
bool possible(vector<int>& stalls, int n, int k, int mid){
    int ct = 1;
    int last = stalls[0];
    for (int i = 1; i < n; i++){
        if (stalls[i] - last >= mid){
            ct++;
            last = stalls[i];
        }
        if (ct >= k) return true;
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(), stalls.end());
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++){
        mini = min(mini, stalls[i]);
        maxi = max(maxi, stalls[i]);
    }
    int low = 1;
    int high = maxi;
    int dist = 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (possible(stalls, n, k, mid)){
            dist = mid;
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }
    return dist;
}

// TC: O(n) + O(nlogn)