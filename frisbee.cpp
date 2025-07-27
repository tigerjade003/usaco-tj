#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
vector<int> nums;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
signed main(){
    setIO();
    cin >> N;
    nums.assign(N, 0);
    for(int i = 0; i<N; i++){
        cin >> nums[i];
    }
    int ans = 0;
    for(int i = 0; i<N; i++){
        int maxs = 0;
        for(int j = i+1; j<N; j++){
            if(maxs > nums[i]) break;
            else if(maxs > nums[j]) continue;
            maxs = nums[j];
            ans += (j - i + 1);
        }
    }
    cout << ans << endl;
}