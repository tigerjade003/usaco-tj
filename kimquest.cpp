#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    cin >> n;
    vector<int> nums;
    nums.reserve(n);
    int even = 0;
    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        k = k % 2;
        nums.push_back(k);
        if(k == 0){
            even++;
        }
    }
    long ans = (even-1) * (even-2) / 2;
    
}