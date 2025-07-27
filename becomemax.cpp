#include <bits/stdc++.h>
using namespace std;
int main() {	
	int T;
	cin >> T;
	while (T--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long lb = 0;
        long long ub = *max_element(a.begin(), a.end()) + k;
        long long ans = 0;
        while (lb <= ub) {
            long long tm = (lb + ub) / 2;
            bool good = false;
            
            for (int i = 0; i < n; i++) {
                vector<long long> min_needed(n);
                min_needed[i] = tm;
                
                long long used = 0;
                for (int j = i; j < n; j++) {
                    if (min_needed[j] <= a[j]) break;
                    
                    if (j + 1 >= n) {
                        used = k + 1;
                        break;
                    }
                    used += min_needed[j] - a[j];
                    min_needed[j + 1] = max(0LL, min_needed[j] - 1);
                }
                if (used <= k) good = true;
            }
            if (good) {
                ans = tm;
                lb = tm + 1;
            } else {
                ub = tm - 1;
            }
        }
        
        cout << ans << endl;
    }
}