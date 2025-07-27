#include <bits/stdc++.h>
using namespace std;

int dif(vector<int>& nums, int t){
    if(nums[t] != 0){
        return nums[t];
    }
    int value = 0;
    if(t == 0){
        value = 1;
    }
    else if(t == 1){
        value = 2;
    }
    else if(t == 2){
        value = 4;
    }
    else{
        value = dif(nums, t-1) + dif(nums, t-2) + dif(nums, t-3); 
    }
    nums[t] = value;
    return value;
}
int main(){
    int t;
    cin >> t;
    vector<int> nums;
    nums.reserve(t);
    for(int i = 0; i<t; i++){
        nums[i] = 0;
    }
    dif(nums, t-1);
    cout << nums[t-1] << endl;
}