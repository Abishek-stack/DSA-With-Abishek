/*
Problem: Best Time to Buy and Sell Stock (LeetCode 121)

Approach:
Implemented the optimal greedy solution directly in one pass by tracking
the minimum buying price so far and updating the maximum profit on the fly.

Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    int buy = prices[0];
    int profit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < buy) {
            buy = prices[i];
        }

        if (prices[i] - buy > profit) {
            profit = prices[i] - buy;
        }
    }

    cout << "Maximum Profit: " << profit << endl;
    cout << "Best Buy Price: " << buy << endl;

    return 0;
}
