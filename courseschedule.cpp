#include <bits/stdc++.h>
using namespace std;
//using DFS
int n, m;
vector<vector<int>> adj;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
vector<int> visited;
vector<int> ans;
bool impossible;
void topsort(int k){
    visited[k] = 1;
    for(auto e: adj[k]){
        if(!visited[e]){
            topsort(e);
        }
        else if(visited[e] == 1){
            impossible  = true;
        }
    }
    ans.push_back(k);
    visited[k] = 2;
}
int main(){
    setIO();
    cin >> n >> m;
    adj.assign(n, vector<int>());
    visited.assign(n, 0);
    for(int i = 0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            topsort(i);
        }
    }
    reverse(ans.begin(), ans.end());
    if(!impossible){
        for(int i = 0; i<n; i++){
            cout << ans[i]+1 << " ";
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}