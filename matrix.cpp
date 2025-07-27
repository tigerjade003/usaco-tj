#include <bits/stdc++.h>
using namespace std;

int search(vector<vector<long long>>& grid, int n, int m){
    if(grid[n][m] != 0){
        return grid[n][m];
    }
    long long  result = 0;
    if(n > 0){
        result += search(grid, n-1, m);
    }
    if(m > 0){
        result += search(grid, n, m-1);
    }
    grid[n][m] = result;
    return result;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> grid;
    grid.reserve(n);
    for(int i = 0; i<n; i++){
        vector<long long> test;
        test.reserve(m);
        for(int i = 0; i<m; i++){
            test.push_back(0);
        }
        grid.push_back(test);
    }
    grid[0][0] = 1;
    search(grid, n-1, m-1);
    cout << grid[n-1][m-1];
}
