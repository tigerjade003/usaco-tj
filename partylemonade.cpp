#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> pow2(31, 1);
    for(int i = 1; i<31; i++){
        pow2[i] = pow2[i-1] * 2;
    }
    int n, l;
    cin >> n >> l;
    vector<pair<long long, pair<long long, long long>>> costs;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a;
        b = a / pow2[i];
        costs.push_back({b, {a, pow2[i]}});
    }
    sort(begin(costs), end(costs));
    long long curcost = (l / costs[0].second.second) * costs[0].second.first;
    long long bestcost = (l / costs[0].second.second + (l % costs[0].second.second == 0 ? 0 : 1) * costs[0].second.first);
    long long remaining = l - ((l / costs[0].second.second) * costs[0].second.second);
    for(int i = 1; i<n-1; i++){
        //do the same thing, but with the last n-i
        cout << bestcost << " " << remaining <<  " " << curcost <<endl;
        curcost += (remaining / costs[i].second.second) * costs[i].second.first;
        bestcost = min(bestcost, curcost + (remaining / costs[i].second.second + (remaining % costs[0].second.second == 0 ? 0 : 1) * costs[i].second.first));
        remaining = remaining - ((remaining / costs[i].second.second) * costs[i].second.second);
    }
    cout << bestcost << endl;
    return 0;
}