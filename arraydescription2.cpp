#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> dp(n, vector<long long>(m+1, 0));
    vector<long long> nums(n, 0);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }
    if(nums[0] == 0){
        for(int j = 1; j<=m; j++){
            dp[0][j] = 1;
        }
    }
    else{
        dp[0][nums[0]] = 1;
    }
    for(int i = 1; i<n; i++){
        if(nums[i] == 0){
            for(int j = 1; j<=m; j++){
                if(j > 0){
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] %= (int)(1e9+7);
                }
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= (int)(1e9+7);
                if(j < m){
                    dp[i][j] += dp[i-1][j+1];
                    dp[i][j] %= (int)(1e9+7);
                }
                /*
                if(j > 0){
                    cout << dp[i-1][j-1] << " ";
                }
                cout << dp[i-1][j] << " ";
                if(j < m-1){
                    cout << dp[i-1][j+1] << " ";
                }
                cout << dp[i][j] << endl;*/
            }
        }
        else{
            if(nums[i]> 0){
                dp[i][nums[i]] += dp[i-1][nums[i]-1];
                dp[i][nums[i]] %= (int)(1e9+7);
            }
            dp[i][nums[i]] += dp[i-1][nums[i]];
            dp[i][nums[i]] %= (int)(1e9+7);
            if(nums[i] < m){
                dp[i][nums[i]] += dp[i-1][nums[i]+1];
                dp[i][nums[i]] %= (int)(1e9+7);
            }
        }
    }
    /*
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    long long ans = 0;
    for(int i = 1; i<=m; i++){
        ans += dp[n-1][i];
        ans %= (int)(1e9+7);
    }
    cout << ans<< endl;
}