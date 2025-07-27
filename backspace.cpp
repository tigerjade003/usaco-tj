#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        string t;
        cin >> t;
        int r1 = s.length()-1;
        int r2 = t.length()-1;
        bool works = true;
        while(r2 >= 0){
            if(r1 < 0){
                works = false;
                break;
            }
            if(s[r1] == t[r2]){
                r1--;
                r2--;
            }
            else{
                r1 -= 2;
            }
        }
        if(!works || r2 > 0 || t.length() > s.length()){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << endl;
    }
}