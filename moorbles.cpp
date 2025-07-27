#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<vector<int>> changes;
vector<int> ans;
int N, M, K;

void find_best_move_seq_starting_with(const vector<int>& seq) {
    if (!ans.empty()) {
        return;
    }
    if (seq.size() == M) {
        ans = seq;
        return;
    }
    for (int parity = 0; parity < 2; ++parity) {
        vector<int> new_seq(seq);
        new_seq.push_back(parity);
        int state = N;
        bool valid = true;
        for (int turn = 0; turn < M; ++turn) {
            if (turn < new_seq.size()) {
                state += changes[turn][new_seq[turn]];
            } else {
                state += *max_element(changes[turn].begin(), changes[turn].end());
            }
            if (state <= 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            find_best_move_seq_starting_with(new_seq);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        changes.clear();
        changes.resize(M, vector<int>(2, numeric_limits<int>::max()));
        ans.clear();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < K; ++j) {
                int a;
                cin >> a;
                int parity = a & 1;
                changes[i][parity] = min(changes[i][parity], a);
                changes[i][parity ^ 1] = min(changes[i][parity ^ 1], -a);
            }
        }
        find_best_move_seq_starting_with({});
        if (ans.empty()) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < M-1; ++i) {
                cout << (ans[i] == 0 ? "Even" : "Odd") << " ";
            }
            cout << (ans[M-1] == 0 ? "Even" : "Odd");
            cout << endl;
        }
    }
    return 0;
}
