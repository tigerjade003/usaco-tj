#include <bits/stdc++.h>
using namespace std;

int t;
int main(){
    cin >> t;
    int dp[200000];
    for(int i = 0; i<9; i++){
        dp[i] = 2;
    }
    dp[9] = 3;
    for(int i = 10; i<200000; i++){
        dp[i] = (dp[i-9] + dp[i-10]) % (int)(1e9+7);
    }
    while(t--){
        int n, m;
        cin >> n >> m;
        int ans = 0;
        while(n > 0){
            int x = n % 10;
            ans += ((m + x < 10) ? 1 : dp[m + x - 10]);
            ans %= (int)(1e9+7);
            n /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}