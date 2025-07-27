#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        for(int j = 0; j<n; j++){
            grid[i][j] = (s[j] == '*');
        }
    }
    /*
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }*/
    vector<vector<long long>> ans(n, vector<long long>(n, 0));
    if(!grid[0][0]){
        ans[0][0] = 1;
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(j < n-1){
                if(!grid[i][j+1]){
                    ans[i][j+1] += ans[i][j];
                    ans[i][j+1] %= (int)(1e9+7);
                }
            }
            if(i < n-1){
                if(!grid[i+1][j]){
                    ans[i+1][j] += ans[i][j];
                    ans[i+1][j] %= (int)(1e9+7);
                }
            }
        }
    }/*
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << ans[n-1][n-1]% (int)(1e9+7) << endl;
}