#include <bits/stdc++.h>
using namespace std;

int t;
int main(){
    cin >> t;
    vector<int> nums;
    nums.reserve(t);
    vector<int> ans;
    ans.reserve(t);
    for(int i = 0; i<t; i++){
        int k;
        cin >> k;
        nums.push_back(k);
        ans.push_back(0);
    }
    ans[0] = 1;
    for(int i = 0; i<t; i++){
        for(int j = i+1; j< i+nums[i]; j++){
            if(j >= t){
                break;
            }
            if(ans[j] == 0){
                ans[j] = ans[i]+1;
            }
            else {
                ans[j] = min(ans[j], ans[i]+1);
            }
        }
    }
    for(int i = 0; i<t; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}