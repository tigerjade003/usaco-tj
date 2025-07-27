#include <bits/stdc++.h>
 
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<char> ok1(n / 2), ok2(n / 2);
    for (int i = 0; i < 2; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < n; ++j) if ((i + j) & 1) {
        ok1[(i + j) / 2] |= (s[j] == '>');
        ok2[(j - i + 1) / 2] |= (s[j] == '>');
      }
    }
    bool ans = true;
    for (int i = 0; i < n / 2; ++i) ans &= ok1[i] && ok2[i];
    cout << (ans ? "YES" : "NO") << '\n';
  }
}