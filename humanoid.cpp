#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long  h;
        cin >> n;
        cin >> h;
        vector<int> powers;
        for(int i = 0; i<n; i++){
            int z;
            cin >> z;
            powers.push_back(z);
        }
        sort(powers.begin(), powers.end());
        int done = 0;
        long long temph = h;
        long long ans = 0;
        long long ans1 = 0;
        long long ans2 = 0;
        for(int i = 0; i<n; i++){
            //cout << temph << " ";
            if(temph > powers[i]){
                temph += (long long)powers[i]/2;
                ans++;
            }
            else{
                done++;
                if(done == 1){
                    temph *= 3;
                    i--;
                }
                else if(done <= 3){
                    temph *= 2;
                    i--;
                }
                else{
                    break;
                }
            }
        }
        //cout << endl;
        temph = h;
        int done2 = 0;
        for(int i = 0; i<n; i++){
            //cout << temph << " ";
            if(temph > powers[i]){
                temph += powers[i]/2;
                ans1++;
            }
            else{
                done2++;
                if(done2 == 2){
                    temph *= 3;
                    i--;
                }
                else if(done2 <= 3){
                    temph *= 2;
                    i--;
                }
                else{
                    break;
                }
            }
        }
        //cout << endl;
        temph = h;
        int done3 = 0;
        for(int i = 0; i<n; i++){
            //cout << temph << " ";
            if(temph > powers[i]){
                temph += powers[i]/2;
                ans2++;
            }
            else{
                done3++;
                if(done3 == 3){
                    temph *= 3;
                    i--;
                }
                else if(done3 <= 3){
                    temph *= 2;
                    i--;
                }
                else{
                    break;
                }
            }
        }
        //cout << endl;
        //cout << done << " " << done2 << " " << done3 << endl;
        //cout << ans << " " << ans1 << " " << ans2 << endl;
        cout << max(max(ans, ans1), ans2) << endl;
    }
    return 0;
}