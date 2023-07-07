/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

/*
- We simply both strings. If the sorted versions of both strings is the same, the strings are anagrams.
*/

#include <string>
using namespace std;
bool isAnagram(string s, string t) {
    string s1 = s;
    string s2 = t;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1 == s2);
}

// TC: O(nlog) -> for sorting
// SC: O(1) -> for quicksort