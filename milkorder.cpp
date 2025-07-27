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
vector<vector<int>> notes;
vector<int> ans;
bool works(int num){
    vector<int> indegree(n, 0);
    vector<vector<int>> adj (n, vector<int>());
    for(int i = 0; i<num; i++){
        int last = notes[i][0];
        for(int j = 1; j<notes[i].size(); j++){
            adj[last].push_back(notes[i][j]);
            indegree[notes[i][j]]++;
            last = notes[i][j];
        }
    }
    set<int> groups;
    for(int i = 0; i<n; i++){
        if(indegree[i] == 0){
            groups.insert(i);
        }
    }
    vector<int> pos;
    while(!groups.empty()){
        pos.push_back(*groups.begin()+1);
        int k = *groups.begin();
        groups.erase(groups.begin());
        for(auto it: adj[k]){
            indegree[it]--;
            if(indegree[it] == 0){
                groups.insert(it);
            }
        }
    }
    if(pos.size() == n){
        ans = pos;
        return true;
    }
    return false;
}
int main(){
    setIO("milkorder");
    cin >> n >> m;
    notes.assign(m, vector<int>());
    for(int i = 0; i<m; i++){
        int k;
        cin >> k;
        for(int j = 0; j<k; j++){
            int x;
            cin >> x;
            x--;
            notes[i].push_back(x);
        }
    }
    int min = 0;
    int max = m;
    while(min < max){
        int mid = min + (max-min+1)/2;
        if(works(mid)){
            min = mid;
        }
        else{
            max = mid-1;
        }
    }
    works(min);
    for(int i = 0; i<ans.size()-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1];
    cout << endl;
}