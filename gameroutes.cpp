#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> ways;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
vector<int> from;
int MOD = 1e9+7;
void topsort(){
    list<int> qu;
    for(int i = 0; i<n; i++){
        if(from[i] == 0){
            qu.push_back(i);
        }
    }
    while(!qu.empty()){
        int k = qu.front();
        qu.pop_front();
        for(auto e: adj[k]){
            ways[e] += ways[k];
            ways[e] %= MOD;
            from[e]--;
            if(from[e] == 0){
                qu.push_back(e);
            }
        } 
    }
}
signed main(){
    setIO();
    cin >> n >> m;
    from.assign(n, 0);
    adj.assign(n, vector<int>());
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        from[b]++;
        adj[a].push_back(b);
    }
    ways.assign(n, 0);
    ways[0] = 1;
    topsort();
    cout << ways[n-1] % MOD << endl;
}