/*
You have N books, each with arr[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book. Out of all the permutations, the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.

Return -1 if an allocation is not possible.
*/

/*
- The key to solving this problem is developing the students function
- Low is the max element of arr
- High is the sum of arr
- We can apply binary search now.
*/

#include <vector>
using namespace std;
int students(vector<int>& arr, int n, int m, int mid){
    int ct = 1;
    long long page_sum = 0;
    for (int i = 0; i < n; i++){
        page_sum += arr[i];
        if (page_sum > mid){
            ct++;
            page_sum = arr[i];
        }
    }
    // cout << "mid = " << mid << endl;
    // cout << "students = " << ct << endl;
    return ct;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    int low = maxi;
    int high = sum;
    int pages = 0;
    // cout << low << " " << high << endl;
    while (low <= high){
        int mid = (high + low) / 2;
        int stud = students(arr, n, m, mid);
        // cout << "Mid = " << mid << endl;
        // cout << "Students = " << stud << endl;
        if (stud > m){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

// TC: O(n) + O(nlogn) ~ O(nlogn)