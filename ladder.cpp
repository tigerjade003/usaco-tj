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
    setIO("ladder");
    int n;
    cin >> n;
    vector<int> values(n+1, 0);
    for(int i = 1; i<=n; i++){
        cin >> values[i];
    }
    vector<int> maxscores(n+1, -1e9);
    maxscores[0] = 0;
    for(int i = 0; i<=n; i++){
        if(i + 1 < n+1){
            maxscores[i+1] = max(maxscores[i+1], maxscores[i] + values[i+1]);
        }
        if(i + 2 < n+1){
            maxscores[i+2] = max(maxscores[i+2], maxscores[i] + values[i+2]);
        }
    }
    cout << maxscores[n] << endl;
    return 0;
}