#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, c;
    cin >> t >> c;
    
    vector<bool> locations(2 * c + 5, false);
    for (int i = 0; i < t; ++i) {
        int pos;
        cin >> pos;
        locations[pos + c] = true;
    }
    
    string command;
    cin >> command;

    unordered_map<int, int> currentHit;
    unordered_map<int, int> whenHit;
    int cur_pos = c;

    for (int i = 0; i < c; ++i) {
        if (command[i] == 'F') {
            if (locations[cur_pos] && currentHit.find(cur_pos) == currentHit.end()) {
                currentHit[cur_pos] = i;
                whenHit[i] = cur_pos;
            }
        }
        if (command[i] == 'L') {
            cur_pos--;
        } else if (command[i] == 'R') {
            cur_pos++;
        }
    }

    int ans = currentHit.size();
    vector<unordered_set<int>> rightSide(5);
    vector<unordered_set<int>> toBeAdded(5);

    for (int i = c - 1; i >= 0; --i) {
        if (whenHit.find(i) != whenHit.end()) {
            currentHit.erase(whenHit[i]);
            whenHit.erase(i);
            for (int j = 0; j < 5; ++j) {
                if (toBeAdded[j].find(cur_pos) != toBeAdded[j].end()) {
                    rightSide[j].insert(cur_pos);
                    toBeAdded[j].erase(cur_pos);
                }
            }
        }
        if (command[i] == 'L') {
            cur_pos++;
        } else if (command[i] == 'R') {
            cur_pos--;
        }
        if(command[i] == 'L'){
            int addL = (locations[cur_pos] && currentHit.find(cur_pos) == currentHit.end() && rightSide[3].find(cur_pos) == rightSide[3].end()) ? 1 : 0;
            ans = max(ans, (int)whenHit.size() + addL + (int)rightSide[3].size());
            ans = max(ans, (int)whenHit.size() + (int)rightSide[4].size());
        }
        else if(command[i] == 'R'){
            int addR = (locations[cur_pos] && currentHit.find(cur_pos) == currentHit.end() && rightSide[1].find(cur_pos) == rightSide[1].end()) ? 1 : 0;
            ans = max(ans, (int)whenHit.size() + addR + (int)rightSide[1].size());
            ans = max(ans, (int)whenHit.size() + (int)rightSide[0].size());
        }
        else{
            ans = max(ans, (int)whenHit.size() + (int)rightSide[1].size());
            ans = max(ans, (int)whenHit.size() + (int)rightSide[3].size());
        }
        if (command[i] == 'F') {
            for (int j = cur_pos - 2; j <= cur_pos + 2; ++j) {
                if (j < 0 || j >= (int)locations.size()) continue;
                if (locations[j]) {
                    if (currentHit.find(j) != currentHit.end()) {
                        toBeAdded[j - cur_pos + 2].insert(j);
                    } else {
                        rightSide[j - cur_pos + 2].insert(j);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
