#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<bool>> graph;
vector<pair<int, int>> all_edges;

void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

bool Valid(vector<vector<bool>>& friends) {
    for (int a = 0; a < N; a++) {
        for (int b = a + 1; b < N; b++) {
            if (!friends[a][b]) continue;
            for (int c = 0; c < N; c++) {
                if (c == a || c == b) continue;
                if (!friends[a][c] && !friends[b][c]) return false; 
            }
        }
    }
    return true;
}

int solve() {
    long long minops = M;
    int E = all_edges.size();
    for (int mask = 0; mask < (1 << E); mask++) {
        vector<vector<bool>> tempGraph = graph;
        long long changes = 0;
        for (int i = 0; i < E; i++) {
            int u = all_edges[i].first, v = all_edges[i].second;
            bool shouldHaveEdge = (mask & (1 << i));
            
            if (tempGraph[u][v] != shouldHaveEdge) {
                tempGraph[u][v] = tempGraph[v][u] = shouldHaveEdge;
                changes++;
            }
            if(changes > minops){
                break;
            }
        }
        if(changes > minops){
            continue;
        }
        if (Valid(tempGraph)) {
            minops = min(minops, changes);
        }
    }
    return minops;
}

int main() {
    setIO();
    cin >> N >> M;
    graph.assign(N, vector<bool>(N, false));
    set<pair<int, int>> seen_edges;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a][b] = graph[b][a] = true;
        seen_edges.insert({a, b});
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            all_edges.push_back({i, j});
        }
    }
    cout << solve() << endl;
}
