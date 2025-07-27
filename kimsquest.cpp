#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= 2;
    }
 
    const int P = 998244353;
    long long ans = 0;
    vector f(n + 1, vector (2, vector<long long> (2)));
    vector g(n + 1, vector (3, vector<long long> (2)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            g[i+1][2][j] = g[i][2][j];
            for (int k = 0; k < 2; ++k) {
                f[i+1][j][k] = f[i][j][k];
                g[i+1][j][k] = g[i][j][k];
            }
        }
 
        if (a[i] == 1) {
            f[i+1][0][1] += f[i][1][0] + g[i][1][0];
            f[i+1][1][1] += f[i][0][1] + g[i][0][1];
 
            ans += f[i][1][0] + g[i][1][0];
            ans += f[i][0][1] + g[i][0][1];
            
            g[i+1][0][1] += g[i][2][0];
            g[i+1][1][1] += g[i][2][1];
            g[i+1][2][1] += 1;
        }
        else {
            f[i+1][1][0] += f[i][1][1] + g[i][1][1];
            f[i+1][0][0] += f[i][0][0] + g[i][0][0];
 
            ans += f[i][1][1] + g[i][1][1];
            ans += f[i][0][0] + g[i][0][0];
 
            g[i+1][1][0] += g[i][2][1];
            g[i+1][0][0] += g[i][2][0];
            g[i+1][2][0] += 1;
        }
 
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                f[i+1][j][k] %= P;
            }
        }
        ans %= P;
    }
 
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    int t = 1;
    // cin >> t;
 
    while (t--) {
        solve();
    }
}