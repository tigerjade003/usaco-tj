#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, s;
vector<int> penalty, prefix;
vector<pair<int, int>> adj[1000001];
vector<vector<pair<int, int>>> adj2;
vector<int> dfs_num, dfs_low, totals, scc;
stack<int> S;
vector<bool> visited;
int timer = 0, scccnt = 0;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
void tarjan(int curr) {
  dfs_low[curr] = dfs_num[curr] = timer++;
  S.push(curr);
  visited[curr] = true;
  for (auto v : adj[curr]) {
    if (dfs_num[v.first] == -1) {
      tarjan(v.first);
    }
    if (visited[v.first]) {
      dfs_low[curr] = min(dfs_low[curr], dfs_low[v.first]);
    }
  }

  if (dfs_num[curr] == dfs_low[curr]) {
    while (true) {
      int v = S.top();
      S.pop();
      visited[v] = false;
      scc[v] = scccnt;
      if (v == curr) {
        break;
      }
    }
    scccnt++;
  }
}
int calc(int w) {
  int lo = 0, hi = 1e8;
  lo--;
  while (hi > lo) {
    int mid = lo + (hi - lo + 1) / 2;
    if (mid * (mid + 1) <= w * 2) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  if (lo == -1)
    return 0;
  return w * lo - prefix[lo];
}
vector<int> dp;
void dfs(int curr) {
  if (dp[curr] == -1)
    return;
  dp[curr] = 0;
  for (auto &[node, w] : adj2[curr]) {
    dfs(node);
    dp[curr] = max(dp[curr], dp[node] + w);
  }
  dp[curr] += totals[curr];
}
signed main() {
  setIO();
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back(make_pair(y, w));
  }
  cin >> s;
  dfs_num.assign(n + 1, -1);
  dfs_low.assign(n + 1, 0);
  visited.assign(n + 1, false);
  scc.assign(n + 1, 0);
  penalty.assign(500000, 0);
  prefix.assign(500001, 0);
  for (int i = 1; i < 500000; i++) {
    penalty[i] = penalty[i - 1] + i;
    prefix[i] += penalty[i] + prefix[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    if (dfs_num[i] == -1) {
      tarjan(i);
    }
  }
  adj2.assign(scccnt, vector<pair<int, int>>());
  totals.assign(scccnt, 0);
  for (int i = 0; i < n; i++) {
    for (auto [node, w] : adj[i]) {
      if (scc[i] != scc[node]) {
        adj2[scc[i]].push_back({scc[node], w});
      } else {
        totals[scc[i]] += calc(w);
      }
    }
  }
  dp.assign(scccnt, -1);
  dfs(s);
  cout << dp[s];
}
