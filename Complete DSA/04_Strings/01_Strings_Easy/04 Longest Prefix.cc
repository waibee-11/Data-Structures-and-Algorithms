/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/

/*
- We check if every letter in the first word is present in every other word.
*/

#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string> &arr, int n)
{
    string prefix = "";
    for (int i = 0; i < arr[0].size(); i++) {
        char curr = arr[0][i];
        // cout << curr << endl;
        bool add = true;
        for (int j = 1; j < arr.size(); j++){
            if (arr[j].size() < i+1 || arr[j][i] != curr){
                add = false;
                break;
            }
        }
        if (add) prefix += curr;
        else break;
    }
    return prefix;
}

// TC: O(n^m) -> n = size of the first word, m -> len of the arr * avg len of each word