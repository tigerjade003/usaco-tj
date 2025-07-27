#include <bits/stdc++.h>
using namespace std;


void setIO(string file = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(file.size())) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
  }
}
long long n;
vector<pair<long long, long long>> cows;
tuple<long long, long long, long long, long long> splitbyx[50000];
tuple<long long, long long, long long, long long> splitbyy[50000];
int main() { 
  setIO("split");
  cin >> n;
  long long minx = 1e9;
  long long maxx = 0;
  long long miny = 1e9;
  long long maxy = 0;
  for(long long i = 0; i<n; i++){
    long long a, b;
    cin >> a >> b;
    minx = min(minx, a);
    maxx = max(maxx, a);
    miny = min(miny, b);
    maxy = max(maxy, b);
    cows.push_back({a, b});
  }
 // cout << minx << " " << maxx << " " << miny << " " << maxy << endl;
  sort(cows.begin(), cows.end());
  long long orig = (maxx-minx)*(maxy-miny);
  minx = 1e9;
  maxx = 0;
  miny = 1e9;
  maxy = 0;
  for(long long i = n-1; i>=0; i--){
    minx = min(minx, cows[i].first);
    maxx = max(maxx, cows[i].first);
    miny = min(miny, cows[i].second);
    maxy = max(maxy, cows[i].second);
    splitbyx[i] = make_tuple(minx, maxx, miny, maxy);
  }
  minx = 1e9;
  maxx = 0;
  miny = 1e9;
  maxy = 0;
  long long temp = orig;
  for(long long i = 0; i<n-1; i++){
    minx = min(minx, cows[i].first);
    maxx = max(maxx, cows[i].first);
    miny = min(miny, cows[i].second);
    maxy = max(maxy, cows[i].second);
    //cout << minx << " " << maxx << " " << miny << " " << maxy;
    if(maxx < get<1>(splitbyx[i+1]) || maxy < get<3>(splitbyx[i+1])){
        temp = min((maxx-minx) * (maxy-miny) + (get<1>(splitbyx[i+1]) - get<0>(splitbyx[i+1])) * (get<3>(splitbyx[i+1]) - get<2>(splitbyx[i+1])), temp);
    }
    //cout << " " << (maxx-minx) * (maxy-miny) + (get<1>(splitbyx[i+1]) - get<0>(splitbyx[i+1])) * (get<3>(splitbyx[i+1]) - get<2>(splitbyx[i+1])) << " " << temp << endl;
  }
  minx = 1e9;
  maxx = 0;
  miny = 1e9;
  maxy = 0;
  for(long long i = 0; i<n; i++){
    long long a = cows[i].first;
    long long b = cows[i].second;
    cows[i].first = b;
    cows[i].second = a;
  }
  sort(cows.begin(), cows.end());
  minx = 1e9;
  maxx = 0;
  miny = 1e9;
  maxy = 0;
  for(long long i = n-1; i>=0; i--){
    minx = min(minx, cows[i].first);
    maxx = max(maxx, cows[i].first);
    miny = min(miny, cows[i].second);
    maxy = max(maxy, cows[i].second);
    splitbyy[i] = make_tuple(minx, maxx, miny, maxy);
  }
  minx = 1e9;
  maxx = 0;
  miny = 1e9;
  maxy = 0;
  for(long long i = 0; i<n-1; i++){
    minx = min(minx, cows[i].first);
    maxx = max(maxx, cows[i].first);
    miny = min(miny, cows[i].second);
    maxy = max(maxy, cows[i].second);
    //cout << minx << " " << maxx << " " << miny << " " << maxy << " ";
    if(maxy < get<3>(splitbyy[i+1]) || maxx < get<1>(splitbyy[i+1])){
        temp = min((maxx-minx) * (maxy-miny) + (get<1>(splitbyy[i+1]) - get<0>(splitbyy[i+1])) * (get<3>(splitbyy[i+1]) - get<2>(splitbyy[i+1])), temp);
    }
    //cout << (maxx-minx) * (maxy-miny) + (get<1>(splitbyy[i+1]) - get<0>(splitbyy[i+1])) * (get<3>(splitbyy[i+1]) - get<2>(splitbyy[i+1])) << " " << temp << endl;
  }
  cout << (orig - temp) << endl;
}