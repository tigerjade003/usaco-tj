#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<long long> nums;
    for(int i = 0; i<t; i++){
        nums.push_back(0);
    }
    nums[0] = 1;
    nums[1] = 2;
    for(int i = 2; i<t; i++){
        nums[i] = nums[i-1] + nums[i-2];
    }
    cout << nums[t-1];
}