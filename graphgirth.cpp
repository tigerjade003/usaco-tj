#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
int ans = 1e9;
const int INF = 1e9;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
void bfs(int start){
    list<pair<int, pair<int, int>>> q;
    vector<int> dist(n+10, INF);
    q.push_back({start, {0, start}});
    while(!q.empty()){
        pair<int, pair<int, int>> a = q.front();
        dist[a.first] = a.second.first;
        q.pop_front();
        for(auto nei: adj[a.first]){
            if(dist[nei] == INF){
                q.push_back({nei, {a.second.first+1, a.first}});
            }
            else if(nei != a.second.second){
                ans = min(ans, a.second.first + 1 + dist[nei]);
            }
        }
    }
}

int main(){
    setIO();
    cin >> n >> m;
    adj.assign(n+10, vector<int>());
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i<=n; i++){
        bfs(i);
    }
    cout << (ans != INF ? ans : -1) << endl;
}