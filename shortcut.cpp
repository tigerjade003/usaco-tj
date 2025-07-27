#include <bits/stdc++.h>
using namespace std;
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
int N, M, T;
vector<vector<pair<int, int>>> adj; 
bool operator<(const struct pair<int, int> a, const struct pair<int, int> b){
    return a.second < b.second;
}
bool sorts(const pair<int, int> a, const pair<int, int> b){
    return a.first < b.first;
}
bool done[10010];
vector<pair<int, vector<int>>> distances;
void dijkstra(int k){
    distances.assign(N+10, {0, vector<int>()});
    multiset<pair<int, pair<int, vector<int>>>> pq;
    pq.insert({k, {0, vector<int>{1}}});
    while(!pq.empty()){
        auto[a, b] = *pq.begin();
        reverse(b.second.begin(), b.second.end());
        reverse(distances[a].second.begin(), distances[a].second.end());
        if((distances[a].first > 0 && distances[a].first >= b.first && distances[a].second >= b.second) || distances[a].first == 0){
            distances[a] = b; 
            done[a] = true;
        }
        reverse(b.second.begin(), b.second.end());
        reverse(distances[a].second.begin(), distances[a].second.end());
        pq.erase(pq.begin());
        for(auto [c, d]: adj[a]){
            if(done[c]){
                if(distances[c].first < b.first || b.second > distances[c].second){
                    continue;
                }
            }
            b.second.push_back(c);
            pq.insert({c, {d+b.first, b.second}});
            b.second.pop_back();
        }
    }
}
int main(){
    setIO("shortcut");
    cin >> N >> M >> T;
    vector<int> numcows;
    for(int i = 0; i<N; i++){
        int a;
        cin >> a;
        numcows.push_back(a);
    }
    adj.assign(N+10, vector<pair<int, int>>());
    for(int i = 0; i<M; i++){
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});
    }
    for(int i = 0; i<N; i++){
        sort(adj[i].begin(), adj[i].end(), sorts);
    }
    dijkstra(1);
    vector<int> check(N+10, 0);
    for(int i = 1; i<=N; i++){
        for(auto k: distances[i].second){
            check[k]+= numcows[i-1];
        }
    }
    long long ans = 0;
    for(int i = 2; i<=N; i++){
        long long temp = (long long)check[i] * max(distances[i].first - T, 0);
        //cout << check[i] << " " << distances[i].first << endl;
        ans = max(ans, temp);
    }
    cout << ans << endl;
}