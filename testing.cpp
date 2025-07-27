#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> nums{6, 3, 0, 3, 8};
    sort(nums.begin(), nums.end());
    for(int i = 0; i<5; i++){
        cout << nums[i] << endl;
    }
}
