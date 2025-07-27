#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
  return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
  fore(i, 0, sz(v)) {
    if(i) out << " ";
    out << v[i];
  }
  return out;
}

int n;
vector<int> a;

inline bool read() {
  if(!(cin >> n))
    return false;
  a.resize(n);
  fore (i, 0, n)
    cin >> a[i];
  return true;
}

bool p(int val, int c1, int c2, int c3) {
  fore (cur1, 0, c1 + 1) fore (cur2, 0, c2 + 1) {
    if (cur1 + 2 * cur2 > val)
      continue;
    if ((val - cur1 - 2 * cur2) % 3 != 0)
      continue;
    if ((val - cur1 - 2 * cur2) / 3 <= c3)
      return true;
  }
  return false;
}

bool possible(int c1, int c2, int c3) {
  for (int v : a) {
    if (!p(v, c1, c2, c3))
      return false;
  }
  return true;
}

inline void solve() {
  int m = *max_element(a.begin(), a.end());
  int ans = int(1e9);
  
  const int MAG = 3;
  fore (c1, 0, MAG) fore (c2, 0, MAG) {
    int c3 = max(0, (m - c1 - 2 * c2 + 2) / 3);
    assert(c1 + 2 * c2 + 3 * c3 >= m);
    
    if (possible(c1, c2, c3))
      ans = min(ans, c1 + c2 + c3);
  }
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  while(t--) {
    read();
    solve();
  }
  return 0;
}