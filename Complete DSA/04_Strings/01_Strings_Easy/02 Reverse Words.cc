/*
Given an input string s, reverse the order of the words.
*/

/*
- We use a for loop to identify words.
- Instead of doing answer + word, we do word + answer to reverse the sentence.
- Use cases for ' '.
*/

#include <string>
using namespace std;
string reverseWords(string s) {
    string answer = "";
    string word = "";
    for (int i = 0; i < s.length(); i++){
        if (s[i] != ' ') word += s[i];
        else{
            if (word != "" && answer != "") word += ' ';
            answer = word + answer;
            word = "";
        }
    }
    if (word != "" && answer != "") word += ' ';
    return word + answer;
}

// TC: O(n)
// SC: O(n) [worst case if the entire string is 1 word]