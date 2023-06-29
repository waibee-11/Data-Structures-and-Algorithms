/*
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

    For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
*/

/*
- We use a stack to keep the track of the number of '(' that we encounter.
- If we encounter a '(' and it is not the outer one (stack size is not 0), then we add it to the answer.
- Similarly for ')', after removing one '(', if the stack is still not empty, we know that ')' is not the closing one.
*/

#include <string>
#include <stack>
using namespace std;
string removeOuterParentheses(string s) {
    string answer = "";
    int n = s.length();
    stack<char> st;
    for (int i = 0; i < n; i++){
        if (s[i] == '('){
            if (st.size() > 0) answer += s[i];
            st.push(s[i]);
        }
        else {
            st.pop();
            if (st.size() > 0) answer += s[i];
        }
    }
    return answer;
}

// TC: O(n)
// SC: O(n/2) ~ O(n) [we only store '(']