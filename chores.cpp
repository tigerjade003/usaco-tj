#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
bool operator<(const pair<int, int> &a, const pair<int, int> &b){
  if(a.second != b.second)
    return a.second < b.second;
  return a.first < b.first;
}
int n;
vector<int> chores;
vector<vector<int>> adj;
vector<int> indegree;
int main(){
  setIO();
  cin >> n;
  chores.assign(n, 0);
  adj.assign(n, vector<int>());
  indegree.assign(n, 0);
  for(int i = 0; i<n; i++){
    int a;
    cin >> a;
    chores[i] = a;
    int k;
    cin >> k;
    indegree[i] = k;
    for(int j = 0; j<k; j++){
      int b;
      cin >> b;
      b--;
      adj[b].push_back(i);
    }
  }
  set<pair<int, int>> qu;
  vector<int> earliest(n, 0);
  for(int i = 0; i<n; i++){
    if(indegree[i] == 0){
      qu.insert({i, chores[i]});
    }
  } 
  while(!qu.empty()){
    auto k = *qu.begin();
    earliest[k.first] = k.second;
    for(auto nei: adj[k.first]){
      indegree[nei]--;
      if(indegree[nei] == 0){
        qu.insert({nei, chores[nei] + k.second});
      }
    }
    qu.erase(qu.begin());
  }
  cout << *max_element(earliest.begin(), earliest.end()) << endl;
}