/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

/*
- You sort the array of pairs
- If the first element of a pair is within the range of the previous pair, then we merge the 2 pairs
*/

#include <vector>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> sol;
    int n = intervals.size();
    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < n; i++){
        if (intervals[i][0] <= end && intervals[i][0] >= start){
            start = min(start,intervals[i][0]);
            end = max(end,intervals[i][1]);
        } else {
            sol.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    sol.push_back({start, end});
    return sol;
}

// TC: O(nlogn) + O(n)