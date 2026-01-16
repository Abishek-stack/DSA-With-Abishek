/*
Problem: Single Number (LeetCode 136)
Every element appears twice except for one element.
Find that single element.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Initial Approach (Sorting + Pair Check):

1. Sort the array.
2. Traverse the array in steps of 2.
3. Compare arr[i] with arr[i - 1]:
   - If they are not equal, arr[i - 1] is the single number.
4. If all pairs match, the last element is the answer.

Time Complexity (TC): O(n log n)
Space Complexity (SC): O(1)   
*/

int singleNumber_sorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 1; i < n; i += 2) {
        if (nums[i] != nums[i - 1]) {
            return nums[i - 1];
        }
    }
    return nums[n - 1];
}

/*
Optimal Approach (Bit Manipulation – XOR):

Using XOR properties:
- x ^ x = 0
- x ^ 0 = x

XOR all elements:
- All duplicate pairs cancel out.
- Remaining value is the single number.

Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
*/

int singleNumber_xor(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        ans = ans ^ nums[i];
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    cout << "Single Number (Sorting Approach): "
         << singleNumber_sorting(nums) << endl;

    cout << "Single Number (XOR Approach): "
         << singleNumber_xor(nums) << endl;

    return 0;
}
