#include <bits/stdc++.h>
using namespace std;

int t;
string l;
int main(){
    cin >> t;
    cin >> l;
    int counter[t];
    for(int i = 1; i<t; i++){ // length of n
        for(int j = 0; j<t-i; j++){ //startt pos of n
            unordered_set<int> maps;
            for(int k = 1; k<=i; i++){ //lenth of substring
                vector<pair<string, int>> str;
                for(int d = j; d<j+i-k; d++){
                    str.push_back({l.substr(d,d+k), d});
                }
                sort(str.begin(), str.end());
                cout << "A";
                cout << str.size();
                maps.insert(j + str[0].second);
            }
            counter[maps.size()]++;
        }
    }
    for(int i = 0; i<t; i++){
        cout << counter[i] << endl;
    }
    return 0;
}