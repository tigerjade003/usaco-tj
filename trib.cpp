#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> answer;
    answer.push_back(-1);
    answer.push_back(0);
    answer.push_back(1);
    for(int i = 3; i<32; i++){
        answer.push_back(answer[i-1] + answer[i-2] + answer[i-3]); 
    }
    while(t--){
        int n;
        cin >> n;
        cout << answer[n+1] << endl;
    }
}