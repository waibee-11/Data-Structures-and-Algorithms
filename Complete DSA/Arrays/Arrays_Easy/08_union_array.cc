/*
Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.
*/

/*
- We use the 2 pointer method. It goes as follows:
    - Set i = 0 and j = 0 for arr1 and arr2 respectively
    - If arr1[i] and arr2[j] are unequal, you add both elements
    - If arr1[i] and arr2[j] are equal, you only add one of them
    - Take advantage of the sorted order
*/

#include <vector>
using namespace std;
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> union_array;
    int i = 0;
    int j = 0;
    while (i < n && j < m){
        if (arr1[i] == arr2[j]){
            if (union_array.empty() || union_array.back() != arr1[i]){
                union_array.push_back(arr1[i]);
            }
            i++;
            j++;
        } else if (arr1[i] < arr2[j]){
            if (union_array.empty() || union_array.back() != arr1[i]){
                union_array.push_back(arr1[i]);
            }
            i++;
        } else {
            if (union_array.empty() || union_array.back() != arr2[j]){
                union_array.push_back(arr2[j]);
            }
            j++;
        }
    }
    
    while (i < n){
        if (union_array.empty() || union_array.back() != arr1[i]){
            union_array.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m){
        if (union_array.empty() || union_array.back() != arr2[j]){
            union_array.push_back(arr2[j]);
        }
        j++;
    }
    return union_array;
}

// TC: O(n + m) since we traverse through both arrays only once
// SC: O(n + m) since in the worst case, all elements could be in the union