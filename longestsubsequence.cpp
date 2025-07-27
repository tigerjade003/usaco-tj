#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
        if(i > 0 && nums[i] == nums[i-1]){
            i--;
            n--;
        }
    }
    vector<int> ans(n, 1);
    int maxs = 1;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(nums[j] < nums[i]){
                ans[i] = max(ans[j]+1, ans[i]);
                maxs = max(maxs, ans[i]);
            }
        }
    }
    cout << maxs << endl;
}