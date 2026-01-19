/*
Problem: Maximum Subarray (LeetCode 53)
Given an integer array nums, find the subarray with the largest sum and return its sum.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Initial Approach (Brute Force):
- Traverse all possible subarrays
- For each subarray, calculate its sum
- Keep track of the maximum sum found

Idea:
- Start index i
- End index j
- Calculate currSum for each (i, j)
- Update maxSum

Time Complexity (TC): O(n^2)
Space Complexity (SC): O(1)
*/

/*
Optimal Approach: Kadane’s Algorithm
- Maintain a running sum (currSum)
- At each index, decide:
    → start a new subarray
    → or extend the existing subarray
- Update maximum sum on the fly

Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution solution;
    int result = solution.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
}
