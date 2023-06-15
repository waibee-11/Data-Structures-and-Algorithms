/*
Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.
*/

/*
- Calculate the prefix sums of all indexes.
- arr[j] - arr[i] = Target if prefix sum of i is arr[j] - target
*/

#include <vector>
#include <map>
using namespace std;
int lenOfLongSubarr(int a[],  int N, int K) { 
    map<int, int> m;
    int len = 0;
    m[0] = -1;
    
    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += a[i];
        if (m.find(sum - K) != m.end()){
            len = max(len, i - m[sum - K]);
        } if (m.find(sum) == m.end()) {
            m[sum] = i;
        }
    }
    return len;
}

// TC: O(n)
// SC: O(n) since we need to store prefix sums for every index