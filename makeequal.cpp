#include <bits/stdc++.h>
using namespace std;

int t;
int main(){
    cin >> t;
    long long moves[(int)1e3];
    fill(begin(moves), end(moves), 0);
    for(int i = 0; i<1e3; i++){
        for(int j = 1; j<=i+1; j++){
            if(i + (i+1)/j < 1e3 && (moves[i+(i+1)/j] == 0 || moves[i + (i+1)/j] > moves[i]+1)){
                moves[i + (i+1)/j] = moves[i]+1;
            }
        }
    }
    while(t--){
        int n, k;
        cin >> n >> k;
        bool remove = false;
        int equals[n];
        int coins[n];
        for(int i = 0; i<n; i++){
            int z;
            cin >> z;
            equals[i] = z;
        }
        for(int i = 0; i<n; i++){
            int z;
            cin >> z;
            coins[i] = z;
        }
        vector<pair<long long, long long>> holder;
        int e = 0;
        int removal = 0;
        for(int i = 0; i<n; i++){
            if(equals[i] == 1){
                e += coins[i];
                remove = true;
                removal++;
            }
            else{
                holder.push_back({moves[equals[i]-1], coins[i]});
            }
        }
        if(remove){
            removal--;
            n -= removal;
        }
        if(e > 0){
            holder.push_back({0, e});
        }
        pair<long long, vector<bool>> ans[k+1];
        unordered_set<int> nodup;
        vector<bool> ka;
        for(int i = 0; i<=k; i++){
            ans[i] = {0, ka};
        }
        queue<int> nums;
        for(int i = 0; i<n; i++){
            if(holder[i].first < k+1){
                if(holder[i].second > ans[holder[i].first].first){
                    ans[holder[i].first].first = holder[i].second;
                    vector<bool> q(n, false);
                    q[i] = true;
                    ans[holder[i].first].second = q;
                    if(!nodup.count(holder[i].first)){
                        nodup.insert(holder[i].first);
                        nums.push(holder[i].first);
                    }
                }
            }
        }
        long long maxs = 0;
        while(!nums.empty()){
            int i = nums.front();
            nums.pop();
            nodup.erase(i);
            if(i > k){
                continue;
            }
            maxs = max(maxs, ans[i].first);
            for(int j = 0; j<n; j++){
                if(!ans[i].second[j] && holder[j].first + i <= k && ans[i].first + holder[j].second > ans[holder[j].first + i].first){
                    ans[holder[j].first + i].first = ans[i].first + holder[j].second;
                    ans[holder[j].first + i].second = ans[i].second;
                    ans[holder[j].first + i].second[j] = true;
                    if(!nodup.count(holder[j].first+i)){
                        nodup.insert(holder[j].first + i);
                        nums.push(holder[j].first + i);
                    }
                }
            }
        }
        cout << maxs << endl;
    }
}