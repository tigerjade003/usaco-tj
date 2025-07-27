#include <bits/stdc++.h>
using namespace std;

unsigned long long nCr(int n, int r) {
    unsigned long long ans = 1;
    for(int i = 1; i<=r; i++){
        ans *= (n-i+1);
        ans /= (i);
        ans %= (int)(1e9+7);
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << nCr(n + 2*m - 1, 2*m)<< endl;
    return 0;
}