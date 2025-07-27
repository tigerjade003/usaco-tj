#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 50000;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int N, M, C, R, K;
vector<pair<int, int>> adj[MAXN];
 
int visits[MAXN];
unordered_set<int> visitors[MAXN];
 
int main() {
    setIO();
 
    cin >> N >> M >> C >> R >> K;
    
    for (int i = 0; i < M; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--, b--;
        adj[a].push_back({b, l});
        adj[b].push_back({a, l});
    }
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for (int i = 0; i < C; i++) {
        pq.push({0, i, i});
    }

    int well_connected = 0;
    while (!pq.empty()) {
        const auto [d, u, r] = pq.top();
        pq.pop();
        if (visits[u] == K || visitors[u].find(r) != visitors[u].end()) {
            continue;
        }
        visits[u] += 1;
        visitors[u].insert(r);
        if (u >= C && visits[u] == K) {
            well_connected += 1;
        }
        for (const auto& [v, l] : adj[u]) {
            if (d + l <= R && visits[v] < K) {
                pq.push({d + l, v, r});
            }
        }
    }
    
    cout << well_connected << "\n";
    for (int i = C; i < N; i++) {
        if (visits[i] == K) {
        cout << i + 1 << "\n";
        }
    }
}