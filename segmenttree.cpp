//template for segment tree

#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b;
vector<int> nums;
vector<int> t;

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v] = nums[tl];
    }
    else{
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1]; 
    }
}
void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        t[v] = new_val;
    }
    else{
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(v * 2, tl, tm, pos, new_val);
        }
        else{
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
int query(int v, int tl, int tr, int l, int r){
    if(l > r){
        return 0;
    }
    if(l == tl && r == tr){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
signed main(){
    setIO();
    cin >> a >> b;
    nums.assign(a, 0);
    t.assign(4*a, 0);
    for(int i = 0; i<a; i++){
        cin >> nums[i];
    }
    build(1, 0, a-1);
    for(int _ = 0; _ < b; _++){
        int cc, dd, ee;
        cin >> cc >> dd >> ee;
        if(cc == 1){
            update(1, 0, a-1, dd-1, ee);
        }
        else{
            cout << query(1, 0, a-1, dd-1, ee-1) << endl;
        }
    }
    cout << endl;
}