/*
Given a number, find the floor of its square root
*/

/*
- Use binary search to eliminate half of the search space in every iteration
*/

long long int floorSqrt(long long int x) {
    long long int low = 1;
    long long int high = x;
    while (low <= high){
        long long int mid = (high + low) / 2;
        if (mid*mid <= x) low = mid + 1;
        else high = mid-1;
    }
    return high;
}

// TC: O(log n)