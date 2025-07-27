#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    nums.reserve(n);
    nums.push_back(1);
    for(int i = 1; i<n; i++){
        nums.push_back(nums[i-1] * (i+1));
    }
    for(int i = 0; i<n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << nums[n-1] << endl;
}