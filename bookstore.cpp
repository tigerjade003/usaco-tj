#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<pair<int, int>> books;
vector<vector<int>> dparr;
int solve(int book, int money){
  if (dparr[book][money] != -1) {
    return dparr[book][money];
  }
  if (money == 0) {
    dparr[book][money] = 0;
    return 0;
  }
  if (book == 0) {
    dparr[book][money] = 0;
    return 0;
  }
  dparr[book][money] = solve(book - 1, money);
  if (money >= books[book].first) {
    dparr[book][money] = max(dparr[book][money], solve(book - 1, money - books[book].first) + books[book].second);
  }
  return dparr[book][money];
}
int main(){
    cin >> n >> x;
    books.push_back({0, 0});
    for(int i = 1; i<=n; i++){
        int k;
        cin >> k;
        books.push_back({k, 0});
    }
    for(int i = 1; i<=n; i++){
        cin >> books[i].second;
    }
    dparr.assign(n+1, vector<int>(x+1, -1));
    cout << solve(n, x) << endl;
}