#include <bits/stdc++.h>
using namespace std;

void setIO(string file = "") {
	cin.tie(0)->sync_with_stdio(0);
	if ((int)(file.size())) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("joseph");
    int N, P;
    cin >> N >> P;
    vector<int> build(N+1, 0);
    build[0] = 0;
    build[1] = 1;
    for(int i = 2; i<=N; i++){
        build[i] = (build[i-1] + P-1) % (i) + 1;
    }
    cout << build[N] << endl;
}