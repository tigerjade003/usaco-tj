#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long long ans;
    long long factorial[10000];
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i<10000; i++){
        factorial[i] = factorial[i-1] * i;
        factorial[i] %= (int)1e9+7;
        if(factorial[i] * (i+1) < 0 && i < 10000-1)
            factorial[i] %= int(1e9+7);
    }
    cout << factorial[n + 2*m - 1] << endl;
    cout << factorial[2*m] % (int)(1e9+7) << endl;
    cout << factorial[n-1] % (int)(1e9+7) << endl;
    cout << (factorial[2 * m] * factorial[n - 1]) % (int)(1e9+7) << endl;
    cout << (factorial[n + 2*m - 1] / ((factorial[2 * m] * factorial[n - 1]) % (int)(1e9+7)));
    
    return 0;
}