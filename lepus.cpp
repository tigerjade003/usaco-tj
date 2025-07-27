#include <bits/stdc++.h>
using namespace std;

void setIO(string file = "") {
	// speed up
	cin.tie(0)->sync_with_stdio(0);
	if ((int)(file.size())) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("lepus");
    int n;
    cin >> n;
    string chars;
    cin >> chars;
    vector<int> ans(n, -1);
    ans[0] = 0;
    for(int i = 0; i<n; i++){
        if(chars[i] != 'w' && ans[i] != -1){
            if(i+1 < n && chars[i+1] != 'w'){
                ans[i+1] = max(ans[i+1], ans[i] + (chars[i+1] == '"'));
            }
            if(i+3 < n && chars[i+3] != 'w'){
                ans[i+3] = max(ans[i+3], ans[i] + (chars[i+3] == '"'));
            }
            if(i+5 < n && chars[i+5] != 'w'){
                ans[i+5] = max(ans[i+5], ans[i] + (chars[i+5] == '"'));
            }
        }
    }
    cout << ans[n-1] << endl;
    return 0;
}