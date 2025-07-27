#include <bits/stdc++.h>

using namespace std;


int main() {

    int t = 1;
    cin >> t;
    while (t--) {
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            vector<long long> dp(m, 1e9);
            vector<int> v(m);
            multiset<long long> mst = {1};
            dp[0] = 1;
            cin >> v[0];
            for (int j = 1; j < m - 1; j++) {
                cin >> v[j];
                dp[j] = *mst.begin() + v[j] + 1;
                if (j - d - 1 >= 0)
                    mst.erase(mst.find((dp[j - d - 1])));
                mst.insert(dp[j]);
            }
            cin >> v.back();
            dp.back() = 1 + *mst.begin();
            a[i] = dp.back();
        }
        long long cur = 0;
        for (int i = 0; i < k; i++)
            cur += a[i];
        long long mins = cur;
        for (int i = k; i < n; i++) {
            cur += a[i] - a[i - k];
            mins = min(cur, mins);
        }
        cout << mins << endl;
    }
    return 0;
}