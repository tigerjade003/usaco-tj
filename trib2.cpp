#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int nums[91];
    nums[60] = 0;
    nums[59] = -1;
    nums[61] = 1;
    for(int i = 62; i<91; i++){
        nums[i] = nums[i-1] + nums[i-2] + nums[i-3];
    }
    for(int i = 58; i>=0; i--){
        nums[i] = nums[i+3] - nums[i+2] - nums[i+1];
    }
    for(int i = 0; i<91; i++){
        cout << nums[i] << endl;
    }
}