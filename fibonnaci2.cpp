#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> nums;
    nums.reserve(n+1);
    nums[0] = 0;
    nums[1] = 1;
    for(int i = 2; i<n+1; i++){
        nums[i] = nums[i-1] + nums[i-2];
    }
    cout << nums[n] << endl;
}