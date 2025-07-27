#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    vector<long long> pow2(33, 0);
    pow2[0] = 1;
    for(int i = 1; i<33; i++){
        pow2[i] = pow2[i-1] * 2;
    }
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<long long> nums(n, 0);
        for(int i = 0; i<n; i++){
            cin >> nums[i];
        }
        vector<vector<long long>> dp(n, vector<long long>(32, 0LL));
        vector<vector<bool>> visited(n, vector<bool>(32, false));
        dp[0][0] = nums[0]-k;
        dp[0][1] = nums[0]/2;
        visited[0][0] = true;
        visited[0][1] = true;
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j<32; j++){
                if(visited[i][j]){
                    long long coinsat = nums[i+1] / pow2[j];
                    if(i < n-1){
                        if(visited[i+1][j]){
                            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + coinsat - k);
                        }
                        else{
                            dp[i+1][j] = dp[i][j] + coinsat - k;
                            visited[i+1][j] = true;
                        }
                    }
                    if(j != 31 && i < n-1){
                        int temp = j+1;
                        if(visited[i+1][j+1]){
                            dp[i+1][j+1] = max(dp[i][j] + coinsat/2, dp[i+1][j+1]);
                        }
                        else{
                            dp[i+1][j+1] = dp[i][j] + coinsat/2;
                            visited[i+1][j+1] = true;
                        }
                    }
                    else if(i < n-1){
                        if(visited[i+1][j]){
                            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                        }
                        else{
                            dp[i+1][j] = dp[i][j];
                        }
                    }
                }
            }
        }/*
        for(int i = 0; i<n; i++){
            for(int j = 0; j<32; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<32; j++){
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }*/
        long long maxx = 0;
        for(int i = 0; i<32; i++){
            maxx = max(maxx, dp[n-1][i]);
        }
        cout << maxx << endl;
    }
}