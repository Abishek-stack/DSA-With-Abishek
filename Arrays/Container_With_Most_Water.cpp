/*
Problem: Container With Most Water (LeetCode 11)
Given n non-negative integers where each represents a vertical line,
find two lines that together with the x-axis form a container such that
the container contains the most water.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Initial Approach (Brute Force):
- Check all pairs (i, j)
- Calculate area = min(height[i], height[j]) * (j - i)
- Keep track of maximum area

Time Complexity (TC): O(n^2)
Space Complexity (SC): O(1)
*/

/*
Optimal Approach (Two Pointers):
- Use two pointers: left (l) and right (r)
- Calculate area using current pointers
- Move the pointer pointing to the smaller height
- This works because area depends on the minimum height

Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
*/

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int n = height.size();
    int l = 0, r = n - 1;
    int maxArea = 0;

    while (l < r) {
        int width = r - l;
        int h = min(height[l], height[r]);
        int currentArea = width * h;

        maxArea = max(maxArea, currentArea);

        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }

    cout << "Maximum Area = " << maxArea << endl;
    return 0;
}
