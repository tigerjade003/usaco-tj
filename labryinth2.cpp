#include <bits/stdc++.h>
using namespace std;

int n, m;
int startx, starty;
int endx, endy;

void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

vector<vector<bool>> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> predecessor;
vector<vector<char>> direction;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<char> moves = {'D', 'U', 'R', 'L'};

void bfs() {
    queue<pair<int, int>> nodes;
    visited.assign(n, vector<bool>(m, false));
    predecessor.assign(n, vector<pair<int, int>>(m, {-1, -1}));
    direction.assign(n, vector<char>(m, ' '));
    
    nodes.push({startx, starty});
    visited[startx][starty] = true;

    while (!nodes.empty()) {
        auto [cx, cy] = nodes.front();
        nodes.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !grid[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                predecessor[nx][ny] = {cx, cy};
                direction[nx][ny] = moves[i];
                nodes.push({nx, ny});

                if (nx == endx && ny == endy) {
                    return; // Stop BFS when end is reached
                }
            }
        }
    }
}

vector<char> reconstructPath() {
    vector<char> path;
    int cx = endx, cy = endy;
    while (!(cx == startx && cy == starty)) {
        char dir = direction[cx][cy];
        path.push_back(dir);
        auto [px, py] = predecessor[cx][cy];
        cx = px;
        cy = py;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    setIO();
    cin >> n >> m;
    grid.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        string e;
        cin >> e;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = (e[j] == '#');
            if (e[j] == 'A') {
                startx = i;
                starty = j;
            }
            if (e[j] == 'B') {
                endx = i;
                endy = j;
            }
        }
    }

    bfs();

    if (!visited[endx][endy]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<char> path = reconstructPath();
        cout << path.size() << endl;
        for (char c : path) {
            cout << c;
        }
        cout << endl;
    }
}
