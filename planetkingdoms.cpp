#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int n, m;
vector<vector<int>> adj;
vector<vector<int>> rev;
int counter = 0;
int nex = 0;
vector<int> visited;
vector<int> order;
vector<int> visited2;
int bob = 0;
void dfsa(int u){
  visited[u] = nex;
  for(auto e: adj[u]){
    if(visited[e] <= 0){
      dfsa(e);
    }
  }
  order.push_back(u);
}
void dfsb(int u){
  visited2[u] = bob;
  for(auto e: rev[u]){
    if(visited2[e]<=0 && visited[e] == visited[u]){
      dfsb(e);
    }
  }
}
int main(){
  cin >> n >> m;
  adj.assign(n, vector<int>());
  rev.assign(n, vector<int>());
  for(int i = 0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    rev[b].push_back(a);
  }
  visited.assign(n, -1);
  visited2.assign(n, -1);
  for(int i = 0; i<n; i++){
    if(visited[i] <=0){
      nex++;
      dfsa(i);
    }
  }
  reverse(order.begin(), order.end());
  for(int k: order){
    if(visited2[k]<=0){
      bob++;
      dfsb(k);
    }
  }
  cout << bob << endl;
  for(auto it: visited2){
    cout << it << " ";
  }
  cout << endl;
}