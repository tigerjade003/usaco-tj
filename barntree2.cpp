#include <bits/stdc++.h>
#define int long long
using namespace std;

struct order{
    int from, to, val;
};
vector<int> cur, subtree_tot;
vector<vector<int>> adj;
int avg, N;
vector<order> orders;

void dfs_fill_subtrees(int node = 0, int par = 0) {
    subtree_tot[node] = cur[node] - avg;
    for (int child : adj[node]){
        if (child != par) {
            dfs_fill_subtrees(child, node);
            subtree_tot[node] += subtree_tot[child];
        }
    }
}

void dfs_make_orders(int node = 0, int par = 0) {
    for (int child : adj[node]){
        if (child != par) {
            if (subtree_tot[child] >= 0) dfs_make_orders(child, node);
            if (subtree_tot[child] > 0){
                orders.push_back({child, node, subtree_tot[child]});
            }
        }
    }
    for (int child : adj[node]){
        if (child != par && subtree_tot[child] < 0) {
            orders.push_back({node, child, -subtree_tot[child]});
            dfs_make_orders(child, node);
        }
    }
}
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
signed main() {
    setIO();
    cin >> N;
    cur.assign(N, 0);
    adj.assign(N, vector<int>());
    for(int i = 0; i<N; i++){
        cin >> cur[i];
        avg += cur[i];
    }
    avg /= N;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    subtree_tot.assign(N, 0);
    dfs_fill_subtrees();
    dfs_make_orders();
    cout << orders.size() << "\n";
    for(int i = 0; i<orders.size(); i++){
        auto [from, to, val] = orders[i];
        cout << from+1 << " " << to + 1 << " " << val << endl;
    }
}