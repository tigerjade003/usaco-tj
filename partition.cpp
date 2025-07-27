#include <bits/stdc++.h>
using namespace std;
bool issubset(vector<int> nums, int n, int sum, vector<vector<int>> dp){
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }
    if (nums[n - 1] > sum)
        return issubset(nums, n - 1, sum, dp);
    return dp[n][sum]
           = issubset(nums, n - 1, sum, dp)
             || issubset(nums, n - 1, sum - nums[n - 1],
                            dp);
}
int main(){
    int n;
    vector<int> sums;
    int sum = 0;
    cin >> n;
    sums.reserve(n);
    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        sums.push_back(k);
        sum += k;
    }
    if(sum%2 == 1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        cout << ((issubset(sums, n, sum, dp) == 1) ? "POSSIBLE" : "IMPOSSIBLE");
    }
}