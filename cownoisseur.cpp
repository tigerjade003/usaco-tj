#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
vector<vector<int>> adj;
int n, m, dfsc;
vector<int> num, low, whatSCC, SCC;
stack<int> S;
vector<bool> visited;
void tarjan(int k){
  low[k] = num[k] = dfsc;
  dfsc++;
  S.push(k);
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
      coin ++;
      if(k == v) break;
    }
    SCC.push_back(coin);
  }
}
vector<vector<int>> adj2;
vector<vector<int>> revadj2;
vector<bool> has0;
vector<bool> has1;
int dpa[100010][2];
int dp(int a, bool b){
  if(dpa[a][b ? 1 : 0] != 0){
    return dpa[a][b ? 1 : 0];
  }
  int ret = -1e9;
  for(int q: adj2[a]){
    ret = max(dp(q, b), ret);
  }
  if(!b){
    for(auto q: revadj2[a]){
      ret = max(dp(q, true), ret);
    }
  }
  if(ret < 0){
    if(has0[a] || (!b && has1[a])){
      dpa[a][b? 1 : 0] = SCC[a];
      return SCC[a];
    }
    else{
      dpa[a][b ? 1 : 0] = -1;
      return -1;
    }
  }
  dpa[a][b ? 1 : 0] = ret + SCC[a];
  return ret + SCC[a];
}
int main(){
  setIO("grass");
  cin >> n >> m;
  adj.assign(n, vector<int>());
  for(int i = 0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--;b--;
    adj[a].push_back(b);
  }
  num.assign(n, -1);
  low.assign(n, 0);
  whatSCC.assign(n, 0);
  visited.assign(n, false);
  for(int i = 0; i<n; i++){
    if(num[i] == -1){
      tarjan(i);
    }
  }
  adj2.assign(SCC.size(), vector<int>());
  revadj2.assign(SCC.size(), vector<int>());
  has0.assign(SCC.size(), false);
  has1.assign(SCC.size(), false);
  for(int i = 0; i<n; i++){
    for(int k: adj[i]){
      if(whatSCC[k] != whatSCC[i]){
        adj2[whatSCC[i]].push_back(whatSCC[k]);
        revadj2[whatSCC[k]].push_back(whatSCC[i]);
        if(whatSCC[i] == whatSCC[0]){
          has1[whatSCC[k]] = true;
        }
        if(whatSCC[k] == whatSCC[0]){
          has0[whatSCC[i]] = true;
        }
      }
    }
  }
  int nums = dp(whatSCC[0], false);
  cout << nums << endl;
}