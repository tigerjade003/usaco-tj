#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
#include <climits>

using namespace std;

void setIO(string file = "") {
	cin.tie(0)->sync_with_stdio(0);
	if ((int)(file.size())) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
}

void topologicalSort(int v, vector<bool>& visited, stack<int>& Stack, const vector<vector<int>>& adj) {
    visited[v] = true;
    for (int i : adj[v]) {
        if (!visited[i]) {
            topologicalSort(i, visited, Stack, adj);
        }
    }
    Stack.push(v);
}


int findLongestPath(int n, const vector<vector<int>>& adj) {
    stack<int> Stack;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSort(i, visited, Stack, adj);
        }
    }

    vector<int> dist(n, INT_MIN);
    dist[Stack.top()] = 0; 

    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();

        if (dist[u] != INT_MIN) {
            for (int v : adj[u]) {
                if (dist[v] < dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                }
            }
        }
    }

    return *max_element(dist.begin(), dist.end());
}

int main() {
    setIO("longpath");

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1); 
    }


    int longestPath = findLongestPath(n, adj);
    cout << longestPath << endl;

    return 0;
}
