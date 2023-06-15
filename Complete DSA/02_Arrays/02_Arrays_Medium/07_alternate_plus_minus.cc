/*
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.

The rearranged array begins with a positive integer.
*/

/*
- Use a 2 pts approach similar to pushing 0's at the end
- Track positive numbers using i and negative numbers using j
- Use some conditions and accordingly keep adding alternate numbers to solution vector
*/

#include <vector>
using namespace std;
vector<int> rearrangeArray(vector<int>& arr) {
    int n = arr.size();
    vector<int> sol;
    int i = 0;
    int j = 0;
    while (i < n && j < n){
        if (arr[i] >= 0 && (sol.empty() || sol.back() < 0)){
            sol.push_back(arr[i]);
            i++;
        }
        if (arr[j] < 0 && !sol.empty() && sol.back() >= 0){
            sol.push_back(arr[j]);
            j++;
        }
        while (i < n && arr[i] < 0){
            i++;
        }
        while (j < n && arr[j] >= 0){
            j++;
        }
    }
    if (i < n) sol.push_back(arr[i]);
    if (j < n) sol.push_back(arr[j]);
    return sol;
}