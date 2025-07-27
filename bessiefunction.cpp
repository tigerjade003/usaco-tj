#include <bits/stdc++.h>
using namespace std;

void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
int N;
vector<int> func, cost, changecost, pointtocost;
vector<bool> needed, done;
int main(){
    cin >> N;
    func.assign(N+1, 0);
    cost.assign(N+1, 0);
    changecost.assign(N+1, 0);
    needed.assign(N+1, true);
    done.assign(N+1, false);
    pointtocost.assign(N+1, 0);
    for(int i = 1; i<=N; i++){
        cin >> func[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> cost[i];
    }
    bool found = false;
    for(int i = 1; i<=N; i++){

        if(func[func[i]] == func[i]){
            needed[i] = false;
            found = true;
            done[i] = true;
        }
        else{
            pointtocost[func[i]] += cost[i];
        }
    }
    long long totcost = 0;
    for(int i = 1; i<=N; i++){
        if(pointtocost[i] != 0 && !done[i] && !done[func[i]]){
            done[i] = true;
            if(cost[i] >= pointtocost[i]){
                totcost += pointtocost[i];
            }
            else{
                totcost += cost[i];
            }
        }
    }
    cout << totcost << endl;
}