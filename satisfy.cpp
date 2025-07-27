#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n, m;
        cin >> n >> m;
        int mn = m;
        int mx = m;
        int last = 0;
        bool works = true;
        for(int i = 0; i<n; i++){
            int t, l, h;
            cin >> t >> l >> h;
            int difference = t - last;
            last = t;
            if(mn - difference <= h && mx + difference >= l){
                mn = max(mn - difference, l);
                mx = min(mx + difference, h);
            }
            else{
                works = false;
            }
        }
        if(works){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
}