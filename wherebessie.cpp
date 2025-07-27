#include <bits/stdc++.h>
using namespace std;

vector<int> x = {0, 0, -1, 1};
vector<int> y = {-1, 1, 0, 0};
int n;
vector<vector<char>> grid;
vector<vector<bool>> visited(20, vector<bool>(20));

void setIO(string file = "") {
	cin.tie(0)->sync_with_stdio(0);
	if ((int)(file.size())) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
}

int startx, starty, endx, endy;

void dfs(int curx, int cury, vector<vector<bool>> &visited, char q){
	if(curx <  startx || curx > endx || cury < starty || cury > endy || visited[curx][cury] || grid[curx][cury] != q){
		return;
	}
	visited[curx][cury] = true;
	for(int i = 0; i<4; i++){
		dfs(curx + x[i], cury + y[i], visited, q);
	}
}

bool isPCL(int startingx, int endingx, int startingy, int endingy){
	startx = startingx;
	endx = endingx;
	starty = startingy;
	endy = endingy;
	fill(visited.begin(), visited.end(), vector<bool>(20));
	vector<int> count(26);
	for(int i = startx; i<=endx; i++){
		for(int j = starty; j<=endy; j++){
			if(!visited[i][j]){
				count[grid[i][j] - 'A']++;
				dfs(i, j, visited, grid[i][j]);
			}
		}
	}
	bool seeone = false;
	bool seetwo = false;
	int counter = 0;
	for(int i = 0; i<26; i++){
		if(count[i] > 0){
			counter++;
		}
		if(count[i] > 1){
			seetwo = true;
		}
		if(count[i] == 1){
			seeone = true;
		}
	}
	/*
	for(int i = 0; i<26; i++){
		cout << count[i] << " ";
	}
	cout << endl << startingx << " " << endingx << " " << startingy << " " << endingy << endl;
	for(int i = startx; i<=endx; i++){
		for(int j = starty; j<=endy; j++){
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << ((counter == 2 && seeone && seetwo) == 0? "False" : "True") << endl;*/
	return (counter == 2 && seeone && seetwo);
}

int main() {
	setIO("where");
	cin >> n;
	for(int i = 0; i<n; i++){
		vector<char> row;
		string q;
		cin >> q;
		for(int j = 0; j<n; j++){
			row.push_back(q[j]);
		}
		grid.push_back(row);
	}
	vector<tuple<int, int, int, int>> PCL;
	int counter = 0;
	for(int startx = 0; startx < n; startx++){
		for(int endx = startx; endx < n; endx++){
			for(int starty = 0; starty < n; starty++){
				for(int endy = starty; endy <n; endy++){
					if(isPCL(startx, endx, starty, endy)){
						PCL.push_back(make_tuple(startx, endx, starty, endy));
					}
				}
			}
		}
	}
	int count = 0;
	for(int i = 0; i<PCL.size(); i++){
		bool isvalid = true;
		tuple<int, int, int, int> a = PCL[i];
		for(int j = 0; j<PCL.size(); j++){
			if(i == j){
				continue;
			}
			tuple<int, int, int, int> b = PCL[j];
			if(get<0>(a) >= get<0>(b) && get<1>(a) <= get<1>(b) && get<2>(a) >= get<2>(b) && get<3>(a) <= get<3>(b)){
				isvalid = false;
				break;
			}
		}
		if(isvalid){
			count++;
		}
	}
	/*
	for(int i = 0; i<PCL.size(); i++){
		tuple<int, int, int, int> e = PCL[i];
		cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << " " << get<3>(e) << endl;
	}
	cout << PCL.size() << endl;
	*/
	cout << count << endl;
	return 0;
}