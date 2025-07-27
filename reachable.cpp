#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
vector<vector<int>> adj, connected;
vector<int> inwhat, sizes;
int N, M, counts, counters;
string len;
vector<bool> visited;
void dfs(int pos, int cur, string len){
    visited[pos] = true;
    //up to cur have been removed
    if(pos <= cur && len[pos] == '0'){
        return;
    }
    if(pos > cur){
        counts++;
    }
    for(auto q: adj[pos]){
        if(!visited[q]){
            dfs(q, cur, len);
        }
    }
}
int count(int cur, string len){
    visited.assign(N, false);
    long long ans = 0;
    for(int i = 0; i<N; i++){
        if(!visited[i]){
            counts = 0;
            dfs(i, cur-1, len);
            ans += (counts * (counts-1))/2;
        }
    }
    return ans;
}
void dfs(int k){
    inwhat[k] = counters;
    connected.rbegin() -> push_back(k);
    for(auto nei: adj[k]){
        if(inwhat[nei] == -1){
            dfs(nei);
        }
    }
}
signed main(){
    setIO("test");
    cin >> N >> M;
    cin >> len;
    adj.assign(N, vector<int>());
    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    inwhat.assign(N, -1);
    int ans = 0;
    for(int i = 0; i<N; i++){
        if(inwhat[i] == -1){
            counters++;
            int z = connected.rbegin() -> size();
            ans += (z * (z-1))/2;
            sizes[counters] = z;
            connected.push_back(vector<int>());
            dfs(i);
        }
    }
    for(int i = 0; i<N; i++){
        cout << ans << endl;
        if(len[i] == '1'){
            ans -= sizes[inwhat[i]];
            sizes[inwhat[i]]--;
        }
    }
}