#include <bits/stdc++.h>
using namespace std;

int dp(int t, vector<int>& count){
    if(count[t] != 0){
        return count[t];
    }
    int result = dp(t-1, count) + dp(t-2, count);
    count[t] = result;
    return result;
}
int main(){
    int t;
    cin >> t;
    vector<int> count;
    count.reserve(t);
    for(int i = 0; i<t; i++){
        count.push_back(0);
    }
    count[0] = 1;
    count[1] = 2;
    dp(t-1, count);
    for(int i = 0; i<t; i++){
        cout << count[i] << " ";
    }
    cout << endl;
    cout << count[t-1] << endl;
}
