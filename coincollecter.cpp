#include <bits/stdc++.h>
using namespace std;
#define int long long
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int n, m;
vector<int> coins;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> low;
vector<int> num;
stack<int> S;
int dfsc;
vector<int> SCC;
vector<int> whatSCC;
vector<vector<int>> adj2;
void tarjan(int k){
  low[k] = dfsc;
  num[k] = dfsc;
  S.push(k);
  dfsc++;
  visited[k] = true;
  for(auto j: adj[k]){
    if(num[j] == -1){
      tarjan(j);
    }
    if(visited[j]){
      low[k] = min(low[k], low[j]);
    }
  }
  if(low[k] == num[k]){
    int coin = 0;
    while(true){
      int v = S.top();
      S.pop();
      visited[v] = false;
      whatSCC[v] = SCC.size();
      coin += coins[v];
      if(k == v) break;
    }
    SCC.push_back(coin);
  }
}
vector<int> indegree;
vector<int> maxxs;
signed main(){
  setIO();
  cin >> n >> m;
  coins.assign(n, 0);
  for(int i = 0; i<n; i++){
    int z;
    cin >> z;
    coins[i] = z;
  }
  adj.assign(n, vector<int>());
  for(int i = 0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
  }
  visited.assign(n, false);
  whatSCC.assign(n, -1);
  low.assign(n, 0);
  num.assign(n, -1);
  dfsc = 0;
  for(int i = 0; i<n; i++){
    if(num[i] == -1){
      tarjan(i);
    }
  }
  adj2.assign(SCC.size(), vector<int>());
  indegree.assign(SCC.size(), 0);
  maxxs.assign(SCC.size(), 0);
  for(int i = 0; i<n; i++){
    for(auto k: adj[i]){
      if(whatSCC[i] != whatSCC[k]){
        if(find(adj2[whatSCC[i]].begin(), adj2[whatSCC[i]].end(), whatSCC[k]) == adj2[whatSCC[i]].end()){
          adj2[whatSCC[i]].push_back(whatSCC[k]);
          indegree[whatSCC[k]]++;
        }
      }
    }
  }
  for(int i = 0; i<SCC.size(); i++){
    maxxs[i] = SCC[i];
  }
  multiset<int> nums;
  for(int i = 0; i<SCC.size(); i++){
    if(indegree[i] == 0){
      nums.insert(i);
    }
  }
  while(!nums.empty()){
    int z = *nums.begin();
    nums.erase(nums.begin());
    for(auto k: adj2[z]){
      maxxs[k] = max(maxxs[z] + SCC[k], maxxs[k]);
      indegree[k]--;
      if(indegree[k] == 0){
        nums.insert(k);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i<SCC.size(); i++){
    ans = max(ans, maxxs[i]);
  }
  cout << ans << endl;
}