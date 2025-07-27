/*
Solution:
Binary search for x in the range 1 ... M
we need to find the best x --> where the number of adds and subtracts is the same
i.e. the number of things that it will be better to add to reach something divisible by M is equal to the number of things that it will be better to subtract to reach something divisible by M
after we find the x that works/the closest one that works --> we find the number of operations needed
output that number
*/
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
int T, N, M;
vector<int> nums, pfx, ptx;
void solve(){
    cin >> N >> M;
    nums.assign(3*N, 0);
    pfx.assign(3*N, 0);
    ptx.assign(3*N, 0);
    for(int i = 0; i<N; i++){
        int k;
        cin >> k;
        nums[i] = k % M;
    }
    for(int i = 0; i<N; i++){
        nums[i+N] = nums[i] + M;
    }
    for(int j = 0; j<N; j++){
        nums[j+2*N] = nums[j] + 2*M;
    }
    sort(nums.begin(), nums.end());
    pfx[0] = nums[0];
    ptx[3*N-1] = nums[3*N-1];
    for(int i = 1; i<3*N; i++){
        pfx[i] = pfx[i-1] + nums[i];
    }
    for(int i = 3*N-2; i>=0; i--){
        ptx[i] = ptx[i+1] + nums[i];
    }
    int ans = LLONG_MAX;
    for(int i = N; i<2*N; i++){
        ans = min(ans, pfx[i + N/2] - (N/2)*nums[i] - pfx[i] + (N-N/2-1)*nums[i] - (ptx[i - (N-N/2-1)] - ptx[i]));
    }
    cout << ans << endl;
}
signed main(){
    setIO();
    cin >> T;
    while(T--){
        solve();
    }
}