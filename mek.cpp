#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> count;
        count.reserve(n);
        for(int i = 0; i<n; i++){
            count.push_back(0);
        }
        for(int i = 0; i<n; i++){
            int p;
            cin >> p;
            count[p]++;
        }
        bool seen = false;
        bool seen2 = false;
        for(int i = 0; i<n; i++){
            if(count[i] == 0){
                seen2 = true;
                cout << i << endl;
                break;
            }
            else if(count[i] == 1){
                if(!seen){
                    seen = true;
                }
                else{
                    seen2 = true;
                    cout << i << endl;
                    break;
                }
            }
        }
        if(!seen2){
            cout << n << endl;
        }
    }
}