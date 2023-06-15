/*
Given an integer array nums, find a sub array that has the largest product, and return the product.
*/

/*
- We use an approach similar to KADANE's algorithm
- We do it in both directions
*/

#include <vector>
using namespace std;
int maxProduct(vector<int>& nums) {
    int max_prod = nums[0];
    int prod = 1;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        prod *= nums[i];
        if (prod > max_prod){
            max_prod = prod;
        }
        if (prod == 0){
            prod = 1;
        }
    }
    prod = 1;
    for (int i = n - 1; i > -1; i--){
        prod *= nums[i];
        if (prod > max_prod){
            max_prod = prod;
        }
        if (prod == 0){
            prod = 1;
        }
    }
    return max_prod;
}