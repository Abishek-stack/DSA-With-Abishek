/*
Problem: Majority Element (LeetCode 169)
An element appears more than n/2 times.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Initial idea (Brute Force):
For each element, count its frequency using nested loops.
If any frequency > n/2, that element is the majority.
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

/*
Optimized Approach: Moore’s Voting Algorithm
Time Complexity: O(n)
Space Complexity: O(1)
*/
int majorityElement(vector<int>& arr) {
    int count = 0, candidate = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        if(count == 0) {
            candidate = arr[i];
        }

        if(arr[i] == candidate)
            count++;
        else
            count--;
    }
    return candidate;
}

int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(arr) << endl;
    return 0;
}
