#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> nums;
    vector<vector<int>> ans;
    nums.reserve(t);
    ans.reserve(t);
    for(int i = 0; i<t; i++){
        int k;
        cin >> k;
        vector<int> q;
        nums.push_back(k);
        ans.push_back(q);
    }
    for(int i = 0; i<t; i++){
        vector<int> inserts;
        for(int j = 0; j<i; j++){
            if(nums[i] == nums[j] + 1 || nums[i] == nums[j]-1){
                if(ans[j].size() + 1 > inserts.size()){
                    inserts = ans[j];
                    inserts.push_back(nums[i]);
                }
            }
        }
        ans[i] = inserts;
    }
    int answer = 0;
    for(int i = 0; i<t; i++){
        int z = ans[i].size();
        answer = max(answer, z);
    }
    for(int i = 0; i<t; i++){
        if(ans[i].size() == answer){
            for(int j: ans[i]){
                cout << j << " ";
            }
            cout << endl;
        }
    }
}