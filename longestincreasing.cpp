#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> nums;
    for(int i = 0; i<t; i++){
        int k;
        cin >> k;
        nums.push_back(k);
    }
    vector<vector<int>> increasing;
    for(int i = 0; i<t; i++){
        vector<int> temp;
        for(int j = 0; j<i; j++){
            if(nums[j] < nums[i]){
                if(temp.size() < increasing[j].size()){
                    temp = increasing[j];
                }
            }
        }
        temp.push_back(nums[i]);
        increasing.push_back(temp);
    }
    int max = -1;
    for(int i = 0; i<t; i++){
        if(max == -1 || increasing[i].size() > increasing[max].size()){
            max = i;
        }
    }
    for(int i = 0; i<t; i++){
        if(increasing[i].size() == increasing[max].size()){
            for(int j: increasing[i]){
                cout << j << " ";
            }
            cout << endl;
        }
    }
}