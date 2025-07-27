#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s == "START"){
        cout << 111111 << endl;
    }
    else if(s == "OBSERVE"){
        string orignum;
        cin >> orignum;
        char q;
        cin >> q;
        int gold = ((orignum[0] - '0') * 100) + ((orignum[1] - '0') * 10) + ((orignum[2]) - '0');
        int silver = ((orignum[3] - '0') * 100) + ((orignum[4] - '0') * 10) + ((orignum[5]) - '0');
        if(q == 'G'){
            gold++;
        }
        else{
            silver++;
        }
        cout << gold << silver;
    }
    else{
        string orignum;
        cin >> orignum;
        int gold = ((orignum[0] - '0') * 100) + ((orignum[1] - '0') * 10) + ((orignum[2]) - '0');
        int silver = ((orignum[3] - '0') * 100) + ((orignum[4] - '0') * 10) + ((orignum[5]) - '0');
        char ans[3];
        ans[0] = 'R';
        ans[1] = 'R';
        ans[2] = 'R';
        if(gold <= 246 && gold >= 226){
            ans[1] = 'G';
        }
        else if(gold <= 346 && gold >= 326){
            ans[0] = 'G';
        }
        else{
            ans[2] = 'G';
        }
        if(silver <= 246 && silver >= 226){
            ans[1] = 'S';
        }
        else if(silver <= 346 && silver >= 326){
            ans[0] = 'S';
        }
        else{
            ans[2] = 'S';
        }
        for(char q: ans){
            if(q == 'R'){
                cout << 'B';
            }
            else{
                cout << q;
            }
        }
        cout << endl;
    }
}