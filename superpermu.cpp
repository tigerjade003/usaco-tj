#include <bits/stdc++.h>
using namespace std;

int t;
int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 2 == 0 || n == 1){
            vector<int> ans;
            ans.push_back(n);
            int removal = 1;
            while(ans.size() < n){
                if(removal % 2 == 1){
                    //it will be n - removal
                    ans.push_back(n-removal);
                }
                else{
                    ans.push_back(removal);
                }
                removal++;
            }
            for(int i: ans){
                cout << i << " ";
            }
        }
        else{
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}