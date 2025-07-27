#include <bits/stdc++.h>
using namespace std;
#define int long long
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int N;
vector<vector<int>> current;
vector<int> curs, precomp;
bool onetwo = true;
signed main(){
    setIO();
    cin >> N;
    current.assign(N, vector<int>());
    precomp.assign(N, 0);
    curs.assign(N, 0);
    for(int i = 0; i<N; i++){
        precomp[i] = (i)*(i+1)/2;
        int a;
        cin >> a;
        if(a != 1 && a != 2){
            onetwo = false;
        }
        current[a-1].push_back(i);
        curs[i] = a-1;
    }
    int ans = 0;
    for(int i = 0; i<N; i++){
        int b;
        cin >> b;
        if(current[b-1].size() == 0){
            continue;
        }
        if(b-1 == curs[i]){
            ans += precomp[i] + precomp[N-i-1];
        }
        for(int j: current[b-1]){
            int left = min(j, i);
            int right = max(j, i);
            ans += min(left, N-right-1) + 1;
        }
    }
    cout << ans << endl;
}
