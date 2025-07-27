#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    cin >> n;
    vector<int> num(n, 0);
    for(int i = 0; i<n; i++){
        cin >> num[i];
    }
    sort(begin(num), end(num));
    vector<int> nums;
    unordered_set<int> e;
    nums.push_back(0);
    e.insert(0);
    for(int i = 0; i<n; i++){
        int zz = nums.size();
        for(int j = 0; j<zz; ++j){
            if(!e.count(nums[j] + num[i])){
                e.insert(nums[j] + num[i]);
                nums.push_back(nums[j] + num[i]);
            }
        }
    }
    sort(begin(nums), end(nums));
    cout << e.size()-1 << endl;
    for(int i = 1; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}