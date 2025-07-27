#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
/*
void setIO(string file = "") {
	cin.tie(0)->sync_with_stdio(0);
	if ((int)(file.size())) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
}*/

int main() {
    //setIO("knapsack");
    int S, N;
    cin >> S >> N;
    vector<int> weights(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }
    vector<int> dp(S + 1, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = S; j >= weights[i]; --j) {
            dp[j] = max(dp[j], dp[j - weights[i]] + weights[i]);
        }
    }

    int maxWeight = *max_element(dp.begin(), dp.end());
    cout << maxWeight << endl;

    return 0;
}
