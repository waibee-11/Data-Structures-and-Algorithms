/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
*/

/*
- Use the prefix sum method discussed in a similar previous problem
*/

#include <vector>
#include <map>
using namespace std;
int maxLen(vector<int>&A, int n){   
    map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    int max_len = 0;
    for (int i = 0; i < n; i++){
        sum += A[i];
        if (mp.find(sum) != mp.end()){
            max_len = max(max_len, i - mp[sum]);
        } else if (mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }
    return max_len;
}

// TC: O(n)
// SC: O(n)