/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
*/

/*
- Use an unordered_set because set.find() is an O(1) operation
- Look for element 'i' such that i - 1 doesn't exist in the set
- Now, keep looking for consecutive elements from 'i' and track the length
- Return max_length
*/

#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int longest = 1;
    int n = nums.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++){
        st.insert(nums[i]);
    }
    for (auto it : st){
        if (st.find(it - 1) == st.end()){
            int len = 1;
            int x = it;
            while (st.find(x + 1) != st.end()){
                len += 1;
                x += 1;
            }
            longest = max(longest, len);
        }
    }
    return longest;
}

// TC: O(n)
// SC: O(n) since we are storing all elements in a set