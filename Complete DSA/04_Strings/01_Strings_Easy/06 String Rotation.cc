/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.
*/

/*
- We use the KMP algorithm. We basically double string s. We will then try to find goal in this new text. If we find it, then we can conclude that goal is a rotation of s.
*/

#include <string>
using namespace std;
bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;
    string text = s+s;
    if (text.find(goal) != string::npos) return true;
    return false; 
}

// TC: O(n) -> n = size of goal