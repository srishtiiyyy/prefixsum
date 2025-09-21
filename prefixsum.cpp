#include <bits/stdc++.h>
using namespace std;

// Optimized solution using prefix sum + hashmap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1; // Base case: sum 0 occurs once
        int prefixsum = 0, count = 0;

        for (int num : nums) {
            prefixsum += num;

            // Check if there exists a prefix with sum = prefixsum - k
            if (freq.find(prefixsum - k) != freq.end()) {
                count += freq[prefixsum - k];
            }

            // Store/update the frequency of current prefixsum
            freq[prefixsum]++;
        }
        return count;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter value of k: ";
    cin >> k;

    Solution sol;
    int ans = sol.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << " is: " << ans << endl;

    return 0;
}
