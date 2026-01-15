/*
Problem: Merge Sorted Array (LeetCode 88)
Given two sorted arrays nums1 and nums2, merge them into nums1 in sorted order.
Initial approach: use an extra array to merge both arrays.
Time Complexity (TC): O(m + n)
Space Complexity (SC): O(m + n) 
In Optimal Method SC :O(1) And TC:O(m+n)
*/

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int arr1[m], arr2[n], arr[m + n];


    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    
    for (int j = 0; j < n; j++) {
        cin >> arr2[j];
    }


    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }


    while (i < m) arr[k++] = arr1[i++];
    while (j < n) arr[k++] = arr2[j++];


    for (int x = 0; x < m + n; x++) {
        cout << arr[x] << " ";
    }
    cout << endl;

    return 0;
}
