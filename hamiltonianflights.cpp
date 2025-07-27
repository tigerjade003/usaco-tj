#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int> adj[21];
int mod = (1e9)+7;
int dp[21][(1<<20) + 1];
signed main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dp[1][1] = 1;
    for(int s = 2; s < (1<<n); ++s){
        if((s & (1 << n-1)) && s != (1<<n)-1){
            continue;
        }
        for(int curr = 1; curr <=n; ++curr){
            if((1 << (curr-1)) & s){
                continue;
            }
            for(auto nei: adj[curr]){
                if(s && (1 << (nei-1))){
                    dp[curr][s] += dp[nei][s - (1<<(curr-1))];
                    dp[curr][s] %= mod;
                }
            }
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<(1<<n)+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][(1<<n)-1] << endl;
}

