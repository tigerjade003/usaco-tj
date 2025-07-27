#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
void setIO(string file = "")
{
    // speed up
    cin.tie(0)->sync_with_stdio(0);
    if ((int)(file.size()))
    {
        (void)! freopen((file + ".in").c_str(), "r", stdin);
        (void)! freopen((file + ".out").c_str(), "w", stdout);
    }
}


struct node{
	int cow;
	int degree;

};
bool cmp(const node& left, const node& right){
	if(left.degree==right.degree) return left.cow < right.cow;
	return left.degree < right.degree;
}
struct dsu{
	vector<int> e;
	void init(int s){
		e.assign(s, -1);
	}
	int get(int u){
		return e[u]<0?u:e[u] = get(e[u]); 
	}
	int same(int u, int v){
		return get(u) == get(v);
	}
	int size(int u){
		return -e[get(u)];
	}
	bool merge(int u, int v){
		u = get(u), v = get(v);
		if(u==v) return false;
		if(e[u] > e[v]) swap(u, v);
		e[u] += e[v];
		e[v] = u;
		return true;
	}
};
signed main(){
	setIO();
	int N, M;
	vector<vector<int>> adj;
	vector<int> deg;
	cin>>N>>M;
	adj.assign(N, vector<int>());
	deg.assign(N, 0);
	set<node, decltype(&cmp)> pq(cmp);
	for(int i = 0; i < M; ++i){
		int a, b;
		cin>>a>>b;
		a--, b--;
		deg[a]++, deg[b]++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < N; ++i){
		pq.insert({i, deg[i]});
	}
	//calculate the min degrees of each node for a group that he may belong
	vector<int> orders;
	vector<bool> removed(N, false);
	while(pq.size()){
		auto curr = *pq.begin();
		orders.push_back(curr.cow);
		deg[curr.cow] = curr.degree;
		removed[curr.cow] = true;
		pq.erase(pq.begin());
		for(auto nbr: adj[curr.cow]){
			if(removed[nbr]) continue;
			pq.erase(pq.find({nbr, deg[nbr]}));
			deg[nbr]--;
			pq.insert({nbr, deg[nbr]});
		}
	}
	//start to calculate the size of each group
	reverse(orders.begin(), orders.end());
	dsu grouping;
	grouping.init(N);
	int ans = 0;
	for(auto i: orders){
		removed[i] = false;
		for(auto nbr: adj[i]){
			if(!removed[nbr]){
				grouping.merge(i, nbr);
				
			}
		}
		ans = max(ans, grouping.size(i) * deg[i]);
	}
	cout<<ans<<endl;
	return 0;
}