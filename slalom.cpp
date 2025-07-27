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
    //setIO("slalom");
    int N;
    cin >> N;
    vector<vector<int>> table(N, vector<int>());
    vector<vector<int>> edit(N, vector<int>());
    for(int i = 0; i<N; i++){
        table[i].assign(i+1, 0);
        edit[i].assign(i+1, -1e9);
        for(int j = 0; j<i+1; j++){
            cin >> table[i][j];
        }
    }
    edit[0][0] = table[0][0];
    for(int i = 0; i<N-1; i++){
        for(int j = 0; j<i+1; j++){
            edit[i+1][j] = max(edit[i+1][j], edit[i][j] + table[i+1][j]);
            edit[i+1][j+1] = max(edit[i+1][j+1], edit[i][j] + table[i+1][j+1]);
        }
    }
    int ans = -1e9;
    for(int i = 0; i<N; i++){
        ans = max(ans, edit[N-1][i]);
    }
    cout << ans << endl;
}