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
        int silver = ((orignum[1] - '0') * 100) + ((orignum[2] - '0') * 10) + ((orignum[3]) - '0');
        int bronze = ((orignum[3] - '0') * 100) + ((orignum[4] - '0') * 10) + ((orignum[5]) - '0');
        if(q == 'G'){
            gold++;
        }
        else if(q == 'B'){
            bronze++;
        }
        else{
            silver++;
        }
        cout << gold << silver << bronze;
    }
    else{
        string orignum;
        cin >> orignum;
        int gold = ((orignum[0] - '0') * 100) + ((orignum[1] - '0') * 10) + ((orignum[2]) - '0');
        int silver = ((orignum[3] - '0') * 100) + ((orignum[4] - '0') * 10) + ((orignum[5]) - '0');
        int bronze = ((orignum[6] - '0') * 100) + ((orignum[7] - '0') * 10) + ((orignum[8]) - '0');
        if(gold < silver && silver < bronze){
            cout << "GSB";
        }
        else if(gold < bronze  && bronze< silver){
            cout << "GBS";
        }
        else if(silver < gold  && gold< bronze){
            cout << "SGB";
        }
        else if(silver < bronze  && bronze< gold){
            cout << "SBG";
        }
        else if(bronze < silver  && silver< gold){
            cout << "BSG";
        }
        else{
            cout << "BGS";
        }
        cout << endl;
    }
}