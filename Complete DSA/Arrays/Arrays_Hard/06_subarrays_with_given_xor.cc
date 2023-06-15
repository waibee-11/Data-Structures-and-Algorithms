/*
Given an array of integers A and an integer B.
Find the total number of sub arrays having bitwise XOR of all elements equals to B.
*/

/*
- We use prefix XOR method
- Similar to the prefix sum method that we used in a question before
*/

#include <vector>
#include <unordered_map>
using namespace std;
int subarraysXor(vector<int> &arr, int x){
    int n = arr.size();
    int ct = 0;
    int xory = 0;
    unordered_map<int, int> mp;
    mp[xory] ++;
    for (int i = 0; i < n; i++){
        xory = xory ^ arr[i];
        int k = xory ^ x;
        ct += mp[k];
        mp[xory]++;
    }
    return ct;
}

// TC: O(n)
// SC: O(n)