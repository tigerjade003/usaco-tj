#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to;
};

vector<vector<int>> adj;
vector<int> answers;

void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
void dfs(int a, int time) {
    if (answers[a] == 0) {
        answers[a] = time;
        for (int b : adj[a]) {
            dfs(b, time);
        }
    }
}
int n, q;
int main() {
    
    setIO();
    cin >> n >> q;

    adj.resize(n + 1);
    answers.assign(n + 1, 0);
    vector<Edge> added;
    vector<Edge> removed(q, {-1, -1});
    vector<int> deactivated(q, 0);
    set<int> alwaysActive;

    for (int a = 1; a <= n; a++) {
        alwaysActive.insert(a);
    }

    for (int j = 0; j < q; j++) {
        char type;
        cin >> type;
        if (type == 'D') {
            int a;
            cin >> a;
            deactivated[j] = a;
            alwaysActive.erase(a);
        } else if (type == 'A') {
            int a, b;
            cin >> a >> b;
            added.push_back({a, b});
        } else if (type == 'R') {
            int k;
            cin >> k;
            if (k - 1 < (int)added.size()) {
                removed[j] = added[k - 1];
                added[k - 1] = {-1, -1}; 
            }
        }
    }

    for (const auto& edge : added) {
        if (edge.from != -1) {
            adj[edge.from].push_back(edge.to);
            adj[edge.to].push_back(edge.from);
        }
    }

    for (int a : alwaysActive) {
        dfs(a, q);
    }

    for (int j = q - 1; j >= 0; j--) {
        if (deactivated[j] != 0) {
            dfs(deactivated[j], j);
        } else if (removed[j].from != -1) {
            int a = removed[j].from, b = removed[j].to;
            adj[a].push_back(b);
            adj[b].push_back(a);
            if (answers[a] != 0 || answers[b] != 0) {
                dfs(a, j);
                dfs(b, j);
            }
        }
    }

    stringstream out;
    for (int a = 1; a <= n; a++) {
        out << answers[a] << '\n';
    }
    cout << out.str();

    return 0;
}
