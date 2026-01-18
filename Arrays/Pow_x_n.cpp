/*
Problem: Pow(x, n) (LeetCode 50)
Compute x raised to the power n (xⁿ).
*/

#include <bits/stdc++.h>
using namespace std;

/*
Initial Approach (Naive):
- Multiply x by itself n times using a loop
- Works only for positive n

Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
Optimal Approach: Binary Exponentiation
- Reduce the power by half at each step
- Handle negative powers using reciprocal

Time Complexity: O(log n)
Space Complexity: O(log n) (recursive stack)
*/

class Solution {
public:
    double solve(double x, long long n) {
        if (n == 0)
            return 1.0;

        if (n % 2 == 0)
            return solve(x * x, n / 2);
        else
            return x * solve(x, n - 1);
    }

    double myPow(double x, int n) {
        long long nn = n;

        if (nn < 0)
            return 1.0 / solve(x, -nn);

        return solve(x, nn);
    }
};

int main() {
    Solution obj;
    double x = 2.0;
    int n = 10;

    cout << "Result: " << obj.myPow(x, n) << endl;
    return 0;
} ready?
