#include <bits/stdc++.h>
using namespace std;

// Your exact Solution class
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixsum(n, 0);
        prefixsum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixsum[i] = nums[i] + prefixsum[i - 1];
        }
        unordered_map<int, int> mpp;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (prefixsum[j] == k) count++;
            int val = prefixsum[j] - k;
            if (mpp.find(val) != mpp.end()) {
                count += mpp[val];
            }
            mpp[prefixsum[j]]++;
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

    // Call function directly without creating an object
    Solution sol;
    int ans = sol.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << " is: " << ans << endl;

    return 0;
}
