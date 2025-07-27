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
vector<vector<int>> curs;
vector<int> cur, pfx, ptx, numin, precomp, lastseen;
signed main(){
    cin >> N;
    curs.assign(N+1, vector<int>());
    cur.assign(N+1, 0);
    precomp.assign(N, 0);
    pfx.assign(N, 0);
    ptx.assign(N, 0);
    numin.assign(N, 0);
    lastseen.assign(N, -1);
    for(int i = 0; i<N; i++){
        precomp[i] = (i)*(i+1)/2;
        pfx[i] = i+1;
        cin >> cur[i];
        if(curs[cur[i]].size() > 0){
            pfx[i] += pfx[*curs[cur[i]].rbegin()];
        }
        curs[cur[i]].push_back(i);
        numin[i] = curs[cur[i]].size();
    }
    for(int i = N-1; i>=0; i--){
        ptx[i] = N-i;
        if(lastseen[cur[i]] > 0){
            ptx[i] += ptx[lastseen[cur[i]]];
        }
        lastseen[cur[i]] = i;
    }
    int ans = 0;
    for(int j = 0; j<N; j++){
        int b;
        cin >> b;
        if(curs[b].empty()) continue;
        if(cur[j] == b){
            ans += precomp[j] + precomp[N-j-1];
        }
        int left = lower_bound(curs[b].begin(), curs[b].end(), j)- curs[b].begin() - 1;//find the number of b that is strictly to the left of the current value
        int right = upper_bound(curs[b].begin(), curs[b].end(), N-j-1) - curs[b].begin(); //find the first b that is strictly to the right of the current value
        if(left >= 0 && right < curs[b].size()-1){
            ans += pfx[curs[b][left]] + ptx[curs[b][right]];
        }
        left = max(0LL, left);
        right = min(((long long)curs[b].size()-1), right);
        ans += (min(curs[b][left], N-curs[b][right]-1) * (numin[curs[b][right]] - numin[curs[b][left]]-2));
    }
    cout << ans << endl;
}