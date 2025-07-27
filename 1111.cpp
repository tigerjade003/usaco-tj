#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    vector<bool> poss;
    for(int i = 0; i<1100; i++){
        poss.push_back(false);
    }
    poss[11] = true;
    poss[111] = true;
    for(int i = 1; i<1100; i++){
        if(poss[i]){
            if(i + 11 < 1100){
                poss[i+11] = true;
            }
            if(i + 111 < 1100){
                poss[i+111] = true;
            }
        }
    }
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n > 1099){
            cout << "YES" << endl;
        }
        else{
            cout << (poss[n] ? ("YES") : ("NO")) << endl;
        }
    }
}