/*
Given an array A of positive integers. Your task is to find the leaders in the array. 

An element of array is leader if it is greater than or equal to all the elements to its right side.

The rightmost element is always a leader. 
*/


/*
- Iterate reverse in the array.
- Keep track of the most recent leader (the last element is the the first leader).
- Any element greater than the most recent leader is also a leader.
- Finally reverse the solution array
*/

#include <vector>
using namespace std;
vector<int> leaders(int a[], int n){
    vector<int> sol;
    int i = n - 1;
    int leader = a[i];
    sol.push_back(leader);
    i--;
    while (i > -1){
        if (a[i] >= leader){
            leader = a[i];
            sol.push_back(leader);
        }
        i--;
    }
    reverse(sol.begin(), sol.end());
    return sol;
}

// TC: O(n)