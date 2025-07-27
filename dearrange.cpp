#include <bits/stdc++.h>
using namespace std;
vector<long long> dearrange;
int findnum(int n){
    if(dearrange[n] != 0){
        return dearrange[n];
    }
    long long ans;
    if(n == 1){
        ans = 0;
    }
    if(n == 2){
        ans = 1;
    }
    else{
        ans = (n-1) * (findnum(n-1) + findnum(n-2));
    }
    dearrange[n] = ans;
    return ans;
}
int n;
int main(){
    cin >> n;
    dearrange.reserve(n+1);
    for(int i = 0; i<n+1; i++){
        dearrange.push_back(0);
    }
    dearrange[1] = 0;
    dearrange[2] = 1;
    cout << endl;
    cout << findnum(n) << endl;
    for(int i = 0; i<n+1; i++){
        cout << dearrange[i] << " ";
    }
}
