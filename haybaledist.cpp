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
int N;
vector<int> locations;
vector<int> pfx;
/*
5
2 4 3 1 5
3
4 3
1 3
3 2
*/
int a, b;
int f(int y){
    auto low=lower_bound(locations.begin(),locations.end(),y);
    int ind=low-locations.begin();
    int l=(ind-1)*a*y-a*pfx[ind-1];
    int r=b*(pfx[N]-pfx[ind-1])-(N-ind+1)*b*y;
    return l+r;
}
int calculate(){
    int l = 0; int r = 1e6+10;
    while(l < r) {
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3;
        if(f(mid1) == f(mid2)){
            l = mid1;
            r = mid2;
        }
        else if(f(mid1) < f(mid2)) {
            r = mid2;
        } else {
            l = mid1;
        }
    }
    return min(f(l), f(r));
}
signed main(){
    //setIO("test");
    cin >> N;
    locations.assign(N, 0);
    int total = 0;
    for(int i = 0; i < N; i++){
        cin >> locations[i];
    }
    sort(locations.begin(), locations.end());
    pfx.assign(N+1, 0);
    for(int i = 0; i < N; ++i){
        total += locations[i];
        pfx[i+1] = total;
    }
    int Q;
    cin >> Q;
    for(int i = 0; i<Q; i++){

        cin >> a >> b;
        for(int i = 0; i <= 10; ++i){
            cout<<f(i)<<" ";
        }
        cout<<endl;

        //cout << calculate() << endl;
    }
}