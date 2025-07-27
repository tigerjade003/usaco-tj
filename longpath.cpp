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
vector<vector<int>> grid(10000, vector<int>(10000, -1));
vector<vector<int>> from(10000, vector<int>());
vector<vector<int>> paths(10000, vector<int>());
void solve(int num){
    for(int j = 0; j<paths[num].size(); j++){
        if(paths[num][j] != -1){
            
        }
    }
}
int main(){
    //setIO("longpath");
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        paths[a-1].push_back(b-1);
        from[b-1].push_back(a-1);
    }
    for(int i = 0; i<n; i++){
        grid[i][i] = 0;
    }
    for(int i = 0; i<n; i++){
        solve(i);
    }
}