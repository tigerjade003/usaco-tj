#include <bits/stdc++.h>
using namespace std;

void setIO(string file = "") {
	cin.tie(0)->sync_with_stdio(0);
	if ((int)(file.size())) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("king2");
    vector<vector<int>> grid(8, vector<int>(8, 0));
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> ans(8, vector<int>(8, -1));
    ans[7][0] = 0;
    for(int i = 7; i>=0; i--){
        for(int j = 0; j<8; j++){
            if(i > 0 &&  j < 7 && (ans[i-1][j+1] == -1 || ans[i-1][j+1] > ans[i][j]+grid[i-1][j+1])){
                ans[i-1][j+1] = ans[i][j] + grid[i-1][j+1];
            }
            if(j != 7 && (ans[i][j+1] == -1 || ans[i][j+1] > ans[i][j] + grid[i][j+1])){
                ans[i][j+1] = ans[i][j] + grid[i][j+1];
            }
            if(i > 0 && (ans[i-1][j] == -1 || ans[i-1][j] > ans[i][j] + grid[i-1][j])){
                ans[i-1][j] = ans[i][j] + grid[i-1][j];
            }
        }
    }
    cout << ans[0][7] << endl;
    return 0;
}