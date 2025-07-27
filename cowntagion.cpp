#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int N;
vector<vector<int>> adj;
vector<int> inbound;
vector<bool> done;
int days = 0;
void dfs(int k){
    int cur = 1;
    done[k] = true;
    int adddays = 0;
    while(cur <= inbound[k]){
        cur *= 2;
        adddays++;
    }
    //cout << adddays << "  BOO   " << cur << " EEEEE" << inbound[k] << endl;
    for(int i : adj[k]){
        if(!done[i]){
            inbound[i]--;
            adddays++;
            dfs(i);
        }
    }
    //cout << k << " " << adddays << endl;
    days += adddays;
}
signed main(){
    if(DEBUG) setIO("test");
    else setIO();
    cin >> N;
    adj.assign(N, vector<int>());
    inbound.assign(N, 0);
    done.assign(N, false);
    for(int i = 0; i<N-1; i++){
        int a, b;
        cin >> a >> b; b--, a--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        inbound[a]++;
        inbound[b]++;
    }/*
    for(int i = 0; i<N; i++){
        cout << inbound[i] << " ";
    }
    cout << endl;*/
    //a cow at location 1 is infected
    dfs(0);
    cout << days << endl;
}