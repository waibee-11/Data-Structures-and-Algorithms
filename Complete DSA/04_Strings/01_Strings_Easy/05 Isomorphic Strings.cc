/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/

/*
- We use a map to map characters of the first string with the second one. We also have to check for a reverse map to ensure that 2 characters are not mapped to the same character.
*/

#include <string>
#include <map>
using namespace std;
bool isIsomorphic_rev(string s, string t){
    map<char, char> mp;
    for (int i = 0; i < s.length(); i++){
        if (!mp[s[i]]) mp[s[i]] = t[i];
        else{
            if (mp[s[i]] != t[i]) return false;
        }
    }
    return true;
}
bool isIsomorphic(string s, string t) {
    map<char, char> mp;
    for (int i = 0; i < s.length(); i++){
        if (!mp[s[i]]) mp[s[i]] = t[i];
        else{
            if (mp[s[i]] != t[i]) return false;
        }
    }
    return true && isIsomorphic_rev(t, s);
}

// TC: O(n)
// SC: O(2n) since we need to create 2 maps