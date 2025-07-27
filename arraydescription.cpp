#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> nums;
int main(){
    cin >> n >> m;
    nums.assign(n, 0);
    vector<pair<int, int>> minmax(n, {1, 1});
    bool fails = false;
    for(int i = 0; i<n; ++i){
        cin >> nums[i];
        if(nums[i] != 0){
            minmax[i] = {nums[i], nums[i]};
        }
        else{
            minmax[i] = {1, m};
        }
        if(i > 0 && nums[i] != 0 && nums[i-1] != 0){
            if(abs(nums[i] - nums[i-1]) > 1){
                fails = true;
            }
        }
    }
    bool found = false;
    for(int i = 0; i<n; i++){
        if(nums[i] != 0){
            found = true;
        }
        if(found && nums[i] == 0){
            minmax[i].first = max(minmax[i-1].first-1, 1);
            minmax[i].second = min(minmax[i-1].second+1, m);
        }
    }
    found = false;
    for(int i = n-1; i>=0; i--){
        if(nums[i] != 0){
            found = true;
        }
        if(found && nums[i] == 0){
            minmax[i].first = max(max(minmax[i+1].first-1, 1), minmax[i].first);
            minmax[i].second = min(min(minmax[i+1].second+1, m), minmax[i].second);
        }
    }
    long long ans = 1;
    for(int i = 0; i<n; i++){
        ans *= (minmax[i].second-minmax[i].first + 1);
        ans %= (int)1e9+7;
    }
    if(!fails)
        cout << ans << endl;
    else
        cout << 0 << endl;
    return 0;
}