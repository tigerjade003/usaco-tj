#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int main(void) {
	int t;
	cin >> t;
	int n, x;
	while (t--) {
		cin >> n;
		vector<int>v(n);
		int cnt = 0, cnt1;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			cnt1 = 0;
			while (x % 2 == 0) {
				cnt++;
				x /= 2;
			}
			int j = i;
			while (j % 2 == 0) {
				cnt1++;
				j /= 2;
			}
			if (cnt1 != 0)v.push_back(cnt1);
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = v.size() - 1; i >= 0 && cnt < n; i--) {
			cnt += v[i];
			ans++;
		}
		if (cnt < n){
            cout << -1 << endl;
        }
		else{
            cout << ans << endl;
        }
	}
}