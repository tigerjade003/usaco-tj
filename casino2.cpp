#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		ll a[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) { cin >> a[i][j]; }
		}

		ll ans = 0;
		for (int i = 0; i < m; i++) {
			vector<ll> temp;
			ll sum = 0;
			for (int j = 0; j < n; j++) {
				temp.push_back(a[j][i]);
				sum += a[j][i];
			}
			ll curr = 0;
			sort(temp.begin(), temp.end());
			for (int j = 0; j < n; j++) {
				curr += temp[j];
				ans += llabs((sum - curr) - (n - 1 - j) * temp[j]);
			}
		}

		cout << ans << "\n";
	}
}