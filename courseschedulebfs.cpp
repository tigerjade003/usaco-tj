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
vector<int> degrees;//inbound
vector<int> ans;
int n, m;
void topsort(){
    list<int> nodes;
    for(int i = 0; i<n; i++){
        if(degrees[i] == 0){
            nodes.push_back(i);
        }
    }
    while(!nodes.empty()){
        int k = nodes.front();
        nodes.pop_front();
        ans.push_back(k);
        for(auto it: adj[k]){
            degrees[it]--;
            if(degrees[it] == 0){
                nodes.push_back(it);
            }
        }
    }
}
int main(){
    setIO();
    cin >> n >> m;
    adj.assign(n, vector<int>());
    degrees.assign(n, 0);
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        degrees[b]++;
    }
    topsort();
    if(ans.size() != n){
        cout << "IMPOSSIBLE";
    }
    else{
        for(auto it: ans){
            cout << it+1 << " ";
        }
    }
    cout << endl;
}