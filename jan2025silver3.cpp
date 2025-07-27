#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int N;
vector<vector<int>> num, ans1, ans2;
vector<int> counts, mapped, mapped1;
bool works1 = true, works2 = true;
void setIO(string file = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}
void print(vector<vector<int>> &a){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout << a[i][j];
            if(j < N-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}
signed main(){
    setIO();
    cin >> N;
    num.assign(N, vector<int>(N, 0));
    ans1.assign(N, vector<int>(N, 0));
    ans2.assign(N, vector<int>(N, 0));
    counts.assign(2*N+1, 0);
    mapped.assign(2*N+1, 0);
    mapped1.assign(2*N+1, 0);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> num[i][j];
            counts[num[i][j]]++;
        }
    }
    if(N == 1){
        cout << 2 << endl;
        return 0;
    }
    int check1 = -1;
    int check2 = -1;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(counts[num[i][j]] == 1){
                if(check1 == -1){
                    check1 = i;
                }
                else{
                    check2 = i;
                }
            }
        }
    }
    for(int i = 0; i<N; i++){
        mapped[num[check1][i]] = counts[num[check1][i]] + 1;
        mapped[num[check2][i]] = 2 * N - counts[num[check2][i]] + 1;
        mapped1[num[check1][i]] = 2 * N - counts[num[check1][i]] + 1;
        mapped1[num[check2][i]] = counts[num[check2][i]] + 1;
    }
    bool print1, checked;
    for(int i = 0; i<N; i++){
        int min1 = 1e9;
        int max1 = 0;
        int min2 = 1e9;
        int max2 = 0;
        for(int j = 0; j<N; j++){
            ans1[i][j] = mapped[num[i][j]];
            min1 = min(min1, ans1[i][j]);
            max1 = max(max1, ans1[i][j]);
            ans2[i][j] = mapped1[num[i][j]];
            min2 = min(min2, ans2[i][j]);
            max2 = max(max2, ans2[i][j]);
            if(ans1[i][j] != ans2[i][j] && !checked){
                print1 = ans1[i][j] < ans2[i][j];
                checked = true;
            }
        }
        if(max2 - min2 != N-1){
            works2 = false;
        }
        if(max1 - min1 != N-1){
            works1 = false;
        }
    }
    if(works1 && works2){
        if(print1){
            print(ans1);
        }
        else{
            print(ans2);
        }
    }
    else if(works1){
        print(ans1);
    }
    else{
        print(ans2);
    }
    return 0;
}
