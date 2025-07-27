#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> access(n, vector<bool>(m, false));
    for(int i = 0; i<n; i++){
        string e;
        cin >> e;
        for(int j = 0; j<m; j++){
            access[i][j] = (e[j] == '1');
        }
    }
    vector<vector<int>> acces(m, vector<int>());
    for(int i = 0; i<m; i++){
        for(int j = i+1; j<m; j++){
            bool one = false;
            bool two = false;
            for(int k = 0; k<n; k++){
                if(access[k][i] && !access[k][j]){
                    one = true;
                }
                if(!access[k][i] && access[k][j]){
                    two = true;
                }
            }
            if(!one || !two){
                acces[i].push_back(j);
                acces[j].push_back(i);
            }
        }
    }
}