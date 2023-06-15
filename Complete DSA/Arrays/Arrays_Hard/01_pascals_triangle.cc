/*
Given an integer numRows, return the first numRows of Pascal's triangle.
*/

/*
- Use the properties of Pascal's Triangles
    - The sum of an element = sum of the 2 elements above it
    - Eg: If we have a row 1 3 3 1, then the
        next row would be 1 4 6 4 1
*/

#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> sol = {{1}};
    for (int i = 1; i < numRows; i++){
        vector<int> row = {1};
        for (int i = 0; i < sol.back().size() - 1; i++){
            row.push_back(sol.back()[i] + sol.back()[i+1]);
        }
        row.push_back(1);
        sol.push_back(row);
    }
    return sol;
}

// TC: O(n)