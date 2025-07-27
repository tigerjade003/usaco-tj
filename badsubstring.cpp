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
    //setIO("badsubs");
    int n;
    cin >> n;
    vector<int> nums(30, 0);
    nums[0] = 0;
    nums[1]= 1;
    for(int j = 2; j < 30; j++){
        nums[j] = 3 * nums[j-1] - nums[j-2];
    }
    cout << nums[n+1];
}