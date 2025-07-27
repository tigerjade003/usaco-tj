#include <bits/stdc++.h>
using namespace std;
#define int long long
void setIO(string file = "") {
	cin.tie(0)->sync_with_stdio(0);
	if ((int)(file.size())) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
}
int N, M, C, R, K;
vector<vector<pair<int, int>>> adj;
struct Node{
    int id, dist, charger;
};
bool operator<(const struct Node a, const struct Node b){
    return a.dist < b.dist; 
}
map<int, bool> done[50500];
void dijkstra(){
    multiset<Node> pq;
    for(int i = 1; i<=C; ++i){
        pq.insert({i, 0, i});
    }
    while(!pq.empty()){
        auto[id, dist, charger] = *pq.begin();
        pq.erase(pq.begin());
        if(done[id].size()>=K || done[id].count(charger)==1){
            continue;
        }
        done[id][charger] = true;
        for(auto[nei, w]: adj[id]){
            int newd = dist + w;
            if(newd > R || done[nei].size() >= K || done[nei].count(charger) == 1){
                continue;
            }
            pq.insert({nei, newd, charger});
        }
    }
}
signed main(){
    setIO();
    cin >> N >> M >> C >> R >> K;
    adj.assign(N+10, vector<pair<int, int>>());
    for(int i = 0; i<M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dijkstra();
    set<int> result;
    for(int i = C+1; i<=N; i++){
        if(done[i].size() >= K){
            result.insert(i);
        }
    }
    cout << result.size() << endl;
    for(auto n: result){
        cout << n <<endl;
    }
}