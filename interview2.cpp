#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<bool> visited;
void dfs(int cur, map<int, unordered_set<int>>& isdup){
    visited[cur] = true;
    for(int k: isdup.find(cur) -> second){
        if(!visited[k]){
            dfs(k, isdup);
        }
    }
}
int main(){
    cin >> n >> k;
    map<long long, vector<int>> farmers;
    for(int i = 0; i<k; i++){
        int zz;
        cin >> zz;
        if(farmers.count(zz)){
            farmers.find(zz) -> second.push_back(i);
        }
        else{
            vector<int> e;
            e.push_back(i);
            farmers.insert({zz, e});
        }
    }
    map<int, unordered_set<int>> isdup;
    for(int i = 0; i<n; i++){
        unordered_set<int> q;
        isdup.insert({i, q});
    }
    bool check = true;
    for(int i = k; i<n; i++){
        int f;
        cin >> f;
        if(farmers.begin() -> second.size() > 1 && check){
            for(int i: farmers.begin() -> second){
                for(int j: farmers.begin() -> second){
                    if(i != j){
                        isdup.find(i) -> second.insert(j);
                        isdup.find(j) -> second.insert(i);
                    }
                }
            }
            check = false;
        }
        long long z = farmers.begin() -> first + f;
        int find = farmers.begin() -> second[0];
        if(farmers.begin() -> second.size() > 1){
            farmers.begin() -> second.erase(farmers.begin() -> second.begin());
        }
        else{
            farmers.erase(farmers.begin());
            check = true;
        }
        if(farmers.count(z)){
            farmers.find(z) -> second.push_back(find);
        }
        else{
            vector<int> q;
            q.push_back(find);
            farmers.insert({z, q});
        }
    }
    auto zz = farmers.begin();
    if(zz -> second.size() > 1){
        auto kk = zz -> second;
        for(int i: kk){
            for(int j: kk){
                if(i != j){
                    isdup.find(i) -> second.insert(j);
                    isdup.find(j) -> second.insert(i);
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        visited.push_back(false);
    }
    int i = farmers.begin() -> second[0];
    dfs(i, isdup);
    cout << farmers.begin() -> first << endl;
    for(int i = 0; i<k; i++){
        cout << visited[i];
    }
    cout << endl;
}