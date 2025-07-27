#include <bits/stdc++.h>
using namespace std;

int n, m;
int startx, starty;
int endx, endy;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
vector<vector<bool>> grid;
vector<vector<vector<char>>> bfsgrid;
vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
vector<char> moves = {'D', 'U', 'R', 'L'};
void bfs(){
    multiset<pair<int, int>> Nodes;
    bfsgrid.assign(n, vector<vector<char>>(m, vector<char>()));
    Nodes.insert({startx, starty});
    while(!Nodes.empty()){
        auto a = *Nodes.begin();
        Nodes.erase(Nodes.begin());
        /*
        if(!bfsgrid[a.first][a.second].empty()){
            continue;
        }*/
        for(int i = 0; i<4; i++){
            if(a.first + x[i] >= 0 && a.first + x[i] < n && a.second + y[i] >= 0 && a.second + y[i] < m && !grid[a.first + x[i]][a.second + y[i]] && (bfsgrid[a.first + x[i]][a.second + y[i]].empty() || bfsgrid[a.first + x[i]][a.second+y[i]].size()-1 > bfsgrid[a.first][a.second].size())){
                bfsgrid[a.first + x[i]][a.second + y[i]] = bfsgrid[a.first][a.second];
                bfsgrid[a.first + x[i]][a.second + y[i]].push_back(moves[i]);
                Nodes.insert({a.first + x[i], a.second + y[i]});
            }
        }
    }
}
int main(){
    setIO("C:\\Users\\jaden\\Downloads\\text file");
    cin >> n >> m;
    grid.assign(n, vector<bool>(m, false));
    for(int i = 0; i<n; i++){
        string e;
        cin >> e;
        for(int j = 0; j<m; j++){
            grid[i][j] = (e[j] == '#');
            if(e[j] == 'A'){
                startx = i;
                starty = j;
            }
            if(e[j] == 'B'){
                endx = i;
                endy = j;
            }
        }
    }
    bfs();
    if(bfsgrid[endx][endy].empty()){
        cout << "NO" << endl; 
    }
    else{
        cout << "YES" << endl;
        cout << bfsgrid[endx][endy].size() <<endl;
        for(auto it: bfsgrid[endx][endy]){
            cout << it;
        }
        cout << endl;
    }
}