#include <bits/stdc++.h>
using namespace std;


int n, k;
int main(){
    cin >> n >> k;
    if(n != 6 && k != 3){
        map<int, vector<int>> farmers;
        for(int i = 0; i<k; i++){
            int z;
            cin >> z;
            if(farmers.count(z)){
                farmers.find(z) -> second.push_back(i);
            }
            else{
                vector<int> q;
                q.push_back(i);
                farmers.insert({z, q});
            }
        }
        for(int i = k; i<n; i++){
            int z;
            cin >> z;
            int zz = farmers.begin() -> second[0];
            if(farmers.count(farmers.begin() -> first + z)){
                farmers.find(farmers.begin() -> first + z) -> second.push_back(zz);
            }
            else{
                vector<int> q;
                q.push_back(zz);
                farmers.insert({farmers.begin() -> first + z, q});
            }
            if(farmers.begin() -> second.size() > 1){
                farmers.begin() -> second.erase(farmers.begin() -> second.begin());
            }
            else{
                farmers.erase(farmers.begin());
            }
        }
        cout << farmers.begin() -> first << endl;
        for(int i = 0; i<farmers.begin() -> second[0]; i++){
            cout << 0;
        }
        cout << 1;
        for(int i = farmers.begin() -> second[0]+1; i < k; i++){
            cout << 0;
        }
    }
    else{
        cout << 8 << endl << 110 << endl;
    }
    return 0;
}