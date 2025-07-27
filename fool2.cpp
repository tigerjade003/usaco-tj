#include <bits/stdc++.h>
using namespace std;

int t;
int main(){
    cin >> t;
    while(t--){
        bool stated = false;
        string q;
        cin >> q;
        for(int i = 0; i<q.length()-1; i++){
            if(q[i] == 'i' && q[i+1] == 't'){
                stated = true;
                break;
            }
        }
        if(stated){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}