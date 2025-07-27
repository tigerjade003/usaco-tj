#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> start;
        vector<int> end;
        for(int i = 0; i<n; i++){
            int k;
            cin >> k;
            start.push_back(k);
        }
        for(int i = 0; i<n; i++){
            int k;
            cin >> k;
            end.push_back(k);
        }
        int maxs = 0;
        for(int i = 0; i<n; i++){
            if(end[i] > start[i]){
                maxs = max(maxs, end[i] - start[i]);
            }
            else{
                maxs = max(maxs, (m-start[i]) + end[i]);
            }
        }
        cout << maxs << endl;
    }
}