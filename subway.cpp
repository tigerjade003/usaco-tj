#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    cin >> n;
    vector<int> in;
    vector<int> out;
    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        in.push_back(k);
    }
    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        out.push_back(k);
    }
    int ans = 0;
    int cur = 0;
    for(int i = 0; i<n; i++){
        cur += out[i];
        cur -= in[i];
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}