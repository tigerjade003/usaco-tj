#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        long long k, x, a, sm=1;
        cin >> k >> x >> a;
        int i;
        for(i = 2; i<=x; ++i){
            long long l = sm/(k-1ll) + 1ll;
            sm += l;
            if(sm > a){
                break;
            }
        }
        if (k * (a - sm) > a && i >= x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}