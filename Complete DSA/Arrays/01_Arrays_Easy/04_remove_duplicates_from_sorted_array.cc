/*Given a sorted array A[] of size N, delete all the duplicated elements from A[].*/

/*
- Set i = 0
- Traverse the array with j until we find an element that is not equal to arr[i]
- We place that element at i+1 index and increment i by 1.
- Finally the number of unique elements is going to be i + 1
*/

int remove_duplicate(int arr[],int n){
    int i = 0;
    int j = 1;
    while (j < n){
        if (arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
        j++;
    }
    return i + 1;
}

// TC: O(n)