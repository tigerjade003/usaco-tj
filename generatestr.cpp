#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<string>> str(7, vector<string>());
    //chars are "a", "b" and "c";
    str[0].push_back("");
    for(int i = 1; i<=5; i++){
        for(int j = 0; j<str[i-1].size(); j++){
            string e = str[i-1][j];
            string b = str[i-1][j];
            bool add = true;
            if(b[b.length()-1] == 'a'){
                add = false;
            }
            string c = str[i-1][j];
            str[i].push_back(e.append("a"));
            if(add){
                str[i].push_back(b.append("b"));
            }
            str[i].push_back(c.append("c"));
        }
    }
    cout << str[5].size() << endl;
    /*
    for(int i = 0; i<str[4].size(); i++){
        cout << str[4][i] << endl;
    }*/
}