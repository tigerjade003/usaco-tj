#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(const std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    vector<int> dp;

    for (const int& x : nums) {
        auto it = std::lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }

    return dp.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }
    cout << lengthOfLIS(nums);
    /*
    std::vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << "Length of LIS: " << lengthOfLIS(arr) << std::endl; // Output: 4*/
    return 0;
}
