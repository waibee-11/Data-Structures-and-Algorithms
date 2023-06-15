/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
*/

/*
- let X -> repeated element & Y -> missing element
- Sum of the first n integers = n(n+1)/2;
- Sum of squares of first n integers = n(n+1)(2n+1)/6;
- Also, our sum = n(n+1)/2 + X - Y;
- And, our squared_sum = n(n+1)(2n+1)/6 + X^2 - Y^2;
- We solve these equations and find values for X and Y
*/

#include <vector>
using namespace std;
vector<int> findTwoElement(vector<int> arr, long long n) {
    long long A = n*(n+1)/2;
    long long B = n*(n+1)*(2*n+1)/6;
    
    for (int i = 0; i < n; i++){
        A -= arr[i];
        B -= (long long) arr[i] * (long long) arr[i];
    }
    
    B = B/A;
    
    long long X = (A + B) / 2;
    long long Y = B - X;
    
    vector<int> sol = {(int)Y,(int)X};
    return {(int)Y,(int)X};
}