#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<long long> nums;
    nums.reserve(t);
    for(int i = 0; i<t; i++){
        nums[i] = 0;
    }
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 4;
    for(int i = 3; i<t; i++){
        nums[i] = nums[i-1] + nums[i-2] + nums[i-3];
    }
    cout << nums[t-1] << endl;
}