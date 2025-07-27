#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  // speed up
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef tuple<int, int, int> tiii;
#define INF 1e9
int N, M;
int lowestF = INF;
struct cmp {
  bool operator()(pll a, pll b) { return a.first > b.first; }
};

void dijkstra(int start, vector<int> &dist, vector<vector<tiii>> &adj, int flow) {
  priority_queue <pll, vector<pll>, cmp> pq;
  pq.push({dist[start], start});
  while (!pq.empty()) {
    long long distance;
    long long curr;
    tie(distance, curr) = pq.top();
    pq.pop();
    if (distance != dist[curr])
      continue;
    for (auto neighbor : adj[curr]) {
      int next;
      int edge;
      int currflow;
      tie(next, edge, currflow) = neighbor;
      if(currflow < flow) continue;
      if (dist[curr] + edge <= dist[next]) {
        dist[next] = dist[curr] + edge;
        lowestF = min(currflow, lowestF);
        pq.push({dist[next], next});
      }
    }
  }
}
int main() {
  setIO("pump");

  cin >> N >> M;
  vector<vector<tiii>> adj(N + 1, vector<tiii>());
  for (int i = 0; i < M; i++) {
    int a, b, c, f;
    cin >> a >> b >> c >> f;
    adj[a].push_back({b, c, f});
    adj[b].push_back({a, c, f});
  }
  vector<int> dist(N+1, INF);
  dist[1] = 0;
  long long result = 0;
  for (int flow = 1; flow <= 1000; flow++){
    dijkstra(1, dist, adj, flow);
    result = max(result,(long long) ((double)(lowestF)/dist[N] * 1e6));
    lowestF=1001;
    dist.assign(N+1, INF);
    dist[1] = 0;
  }
  cout<<result<<endl;

  return 0;
}