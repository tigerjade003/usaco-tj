#include <bits/stdc++.h>
using namespace std;

int t;
int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string even = "";
        string odd = "";
        for(int i = 0; i<n; i++){
            if(i % 2 == 0){
                even += "##";
                odd += "..";
            }
            else{
                even += "..";
                odd += "##";
            }
        }
        for(int i = 0; i<n; i++){
            if(i % 2 == 0){
                cout << even << endl;
                cout << even << endl;
            }
            else{
                cout << odd << endl;
                cout << odd << endl;
            }
        }
    }
}
