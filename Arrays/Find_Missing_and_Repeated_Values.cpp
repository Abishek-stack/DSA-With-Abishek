/*
Problem: Find Missing and Repeated Values (LeetCode 2965)
A number in range [1, n^2] is repeated once and another is missing.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Initial idea (Brute Force):
Store values in a 2D matrix.
For each element, count its occurrences using nested loops.
The value with count = 2 is the repeated number.
Then check from 1 to n^2 to find the missing number.
Time Complexity: O(n^4)
Space Complexity: O(1)
*/

/*
Optimized Approach (Math):
Use sum and sum of squares formulas.
Let a be repeated, b be missing.
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    long long N = 1LL * n * n;

    long long actualSum = 0, actualSqSum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            actualSum += grid[i][j];
            actualSqSum += 1LL * grid[i][j] * grid[i][j];
        }
    }

    long long expectedSum = N * (N + 1) / 2;
    long long expectedSqSum = N * (N + 1) * (2 * N + 1) / 6;

    long long diff = actualSum - expectedSum;        // actualSum = expectedSum + a - b
    long long sqDiff = actualSqSum - expectedSqSum;  // actualSqSum = expectedSqSum + a^2 - b^2

    long long sum = sqDiff / diff;                   // a + b

    int repeated = (diff + sum) / 2;
    int missing = repeated - diff;

    return {repeated, missing};
}

int main() {
    vector<vector<int>> grid = {
        {1, 3},
        {2, 2}
    };

    vector<int> ans = findMissingAndRepeatedValues(grid);
    cout << "Repeated: " << ans[0] << ", Missing: " << ans[1] << endl;

    return 0;
}
