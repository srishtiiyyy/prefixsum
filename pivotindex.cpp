#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given an array, find the pivot index where the sum of elements on the left 
is equal to the sum of elements on the right. 
Return -1 if no such index exists.
*/

// ---------------- BRUTE FORCE APPROACH ----------------
// Time Complexity: O(n^2), Space: O(1)
int pivotIndexBrute(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int leftSum = 0, rightSum = 0;

        // Calculate sum of elements to the left of i
        for (int j = 0; j < i; j++) {
            leftSum += nums[j];
        }
        // Calculate sum of elements to the right of i
        for (int j = i + 1; j < n; j++) {
            rightSum += nums[j];
        }

        if (leftSum == rightSum) return i; // Pivot index found
    }
    return -1; // No pivot index
}

// ---------------- OPTIMIZED APPROACH ----------------
// Time Complexity: O(n), Space: O(1)
int pivotIndexOptimized(vector<int>& nums) {
    int n = nums.size();
    
    // Step 1: Calculate total sum
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
    }
    
    // Step 2: Traverse and check pivot
    int leftSum = 0;
    for (int i = 0; i < n; i++) {
        // rightSum = totalSum - leftSum - nums[i]
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i; // Pivot index found
        }
        leftSum += nums[i];
    }
    return -1; // No pivot index
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Call brute force function
    cout << "Pivot Index (Brute Force): " << pivotIndexBrute(nums) << endl;

    // Call optimized function
    cout << "Pivot Index (Optimized): " << pivotIndexOptimized(nums) << endl;

    return 0;
}