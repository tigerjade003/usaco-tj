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
    //build the graph (but also keep track of the degrees of nodes)
    //use a set or priority queue to store the nodes and their degrees
    //go through the nodes in the set/pq from smallest degree to largest degree
    //remove them one after another and update the nodes in the set/pq who are connected to the 
    //removed node (i.e. deg-1)

    //start to add nodes into the graph using dsu
    //ans = max(ans, node[i]'s degree * size of the group node i belongs to)
}