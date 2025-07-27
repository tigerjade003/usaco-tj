#include <bits/stdc++.h>
using namespace std;
int fib(int n, vector<unsigned long long>& nums){
    unsigned long long result;
    if(nums[n] != 0){
        return nums[n];
    }
    else if(n == 0 || n == 1){
        result = 1;
    }
    else{
        result = (unsigned long long)fib(n-1, nums) + (unsigned long long)fib(n-2, nums);
    }
    nums[n] = result;
    return result;
}
int main(){
    int n;
    cin >> n;
    vector<unsigned long long> nums(n, 0L);
    fib(n-1, nums);
    cout << nums[n-1] << endl;
}