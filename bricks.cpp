#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int w, h, b, m;
        cin >> w >> h >> b >> m;
        vector<int> bricks;
        for(int i = 0; i<b; i++){
            bricks.push_back(0);
        }
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
                int z;
                cin >> z;
                if(z != 0){
                    bricks[z-1]++;
                }
            }
        }
        sort(bricks.begin(), bricks.end());
        long long ans = 0;
        for(int i = 0; i<m; i++){
            ans += bricks[i];
        }
        cout << ans << endl;
    }
}