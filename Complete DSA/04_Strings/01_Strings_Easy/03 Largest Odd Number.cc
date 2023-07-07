/*
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.
*/

/*
- We simply scan every digit from right to left.
- If we find an odd digit, we return the substring until that digit.
- If no odd digit is found, we return "".
*/

#include <string>
using namespace std;
string largestOddNumber(string num) {
    int i = num.size() - 1;
    while (i >= 0){
        if (num[i] % 2) return num.substr(0, i+1);
        else i--;
    }
    return "";
}

// TC: O(n)