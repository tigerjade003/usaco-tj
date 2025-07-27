#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Nodes{
    int id;
    int dist;
};
bool operator<(const Nodes& a, const Nodes& b){
    return a.dist < b.dist;
}
int n, m, c, r, k;
vector<pair<int, int>> adj[50050];
vector<int> dist(50050, 1e18);
vector<bool> done(50500, false);
int cnt;
void dijkstra(int src)
{
  multiset<Nodes> pq;
  pq.insert({src, 0});
  dist[src] = 0;
  while(!pq.empty()){
    Nodes curr = *pq.begin();
    pq.erase(pq.begin());
    if(done[curr.id]) continue;
    done[curr.id] = true;
    if(curr.id <= c) cnt++;
    for(auto nei: adj[curr.id]){
      int nid = nei.first;
      int w = nei.second;
      if(done[nid]) continue;
      if(dist[nid] > dist[curr.id] + w && dist[curr.id] + w <= r){
        dist[nid] = dist[curr.id] + w;
        pq.insert({nid, dist[nid]});
      }
    }
  }
}
signed main(){
    cin >> n >> m >> c >> r >> k;
    for(int i = 0; i<m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        a--;
        b--;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    set<int> result;
    for(int j = c; j<n; j++){
        dijkstra(j);
        if(cnt >= k){
            result.insert(j);
        }
        dist.assign(50050, 1e18);
        cnt = 0;
    }
}
