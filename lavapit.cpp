#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>> blocks;
        for(int i = 0; i<n; i++){
            string c;
            cin >> c;
            vector<char> js;
            for(int j = 0; j<m; j++){
                js.push_back(c[j]);
            }
            blocks.push_back(js);
        }
        //now do 
    }
}