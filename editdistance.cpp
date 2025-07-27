#include <bits/stdc++.h>
using namespace std;

int main(){
    string n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> dp(n.length()+1, vector<int>(m.length()+1, 1e9));
    for (int i = 0; i <= n.length(); ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m.length(); ++j) {
        dp[0][j] = j;
    }
    for(int i = 1; i<=n.length(); i++){
        for(int j = 1; j<=m.length(); j++){
            if(n[i-1] == m[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min({dp[i][j-1] + 1, dp[i-1][j-1] + 1, dp[i-1][j] + 1});
            }
        }
    }
    for(int i = 0; i<n.length(); i++){

    }
    cout << dp[n.length()][m.length()] << endl;
}