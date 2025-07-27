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
    //setIO("balls");
    int T;
    cin >> T;
    vector<int> pyramids;
    pyramids.push_back(1);
    vector<int> dsum;
    dsum.push_back(1);
    int index = 1;
    while(pyramids[pyramids.size()-1] < 300000){
        index++;
        dsum.push_back(index + dsum[dsum.size()-1]);
        pyramids.push_back(dsum[dsum.size()-1] + pyramids[pyramids.size()-1]);
    }
    vector<int> pyramidsizes(300001, -1);
    pyramidsizes[0] = 0;
    for(int i = 0; i<300001; i++){
        for(int j = 0; j<pyramids.size(); j++){
            if(i + pyramids[j] < 300001 && (pyramidsizes[i+pyramids[j]] == -1 || pyramidsizes[i+pyramids[j]] > pyramidsizes[i] + 1)){
                pyramidsizes[i+pyramids[j]] = pyramidsizes[i]+1;
            }
        }
    }
    while(T--){
        int k;
        cin >> k;
        cout << pyramidsizes[k] << endl;
    }
    return 0;
}