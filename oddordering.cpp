#include <bits/stdc++.h>
using namespace std;
int pow2(int n){
    int a = 1;
    int counter = 0;
    while(a < n){
        counter++;
        a *= 2;
    }
    if(a == n){
        return counter;
    }
    else{
        return counter-1;
    }
}
int main(){
    int t;
    cin >> t;
    int pow2s[31];
    pow2s[0] = 1;
    for(int i = 1; i<31; i++){
        pow2s[i] = pow2s[i-1] * 2;
    }
    while(t--){
        int k, n;
        cin >> n >> k;
        int found = 0;
        int i;
        int z = pow2(n);
        for(i = 0; i<=z; i++){
            int count = (n-pow2s[i])/(2*pow2s[i])+1;
            found += count;
            if(found >= k){
                break;
            }
        }
        int num = (n-pow2s[i])/(2*pow2s[i])+1;
        int extra = found - k;
        int pos = num - extra;
        cout << (pow2s[i]) + ((pos-1) * 2 * pow2s[i]) << endl;
    }
}
