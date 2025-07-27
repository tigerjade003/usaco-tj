#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    long long counter = 0;
    vector<pair<long long, long long>> cows; 
    for(long long i = 0; i<n; i++){
        long long a, b;
        cin >> a >> b;
        cows.push_back({a, b});
    }
    sort(begin(cows), end(cows));
    map<long long, long long> towers;
    towers.insert({0, m});
    long long ans = 0;
    for(long long i = 0; i<n; i++){
        while(cows[i].second != 0){
            if(towers.begin() -> first == 0 || towers.begin() -> first + k <= cows[i].first){
                long long kk = min(cows[i].second, towers.begin() -> second);
                if(towers.count(cows[i].first)){
                    towers.find(cows[i].first)->second+=kk;
                }
                else{
                    towers.insert({cows[i].first, kk});
                }
                ans+=kk;
                cows[i].second-= kk;
                towers.begin() -> second-=kk;
                if(towers.begin() -> second == 0){
                    towers.erase(towers.begin());
                }
            }
            else{
                break;
            }
        }
    }
    cout << ans << endl;
}