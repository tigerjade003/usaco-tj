#include <bits/stdc++.h>
using namespace std;

int main(){
    int jobs;
    cin >> jobs;
    vector<tuple<long long, long long, long long>> job;
    for(int i = 0; i<jobs; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        job.push_back(make_tuple(a, b, c));
    }
    sort(job.begin(), job.end(), [](const tuple<long long, long long, long long>& a, const tuple<long long, long long, long long>& b) {
        return get<1>(a) < get<1>(b);
    });
    vector<long long> profits;
    profits.reserve(jobs);
    profits.push_back(get<2>(job[0]));
    for(int i = 1; i<jobs; i++){
        long long maxprofit = 0;
        for(int j = 0; j<i; j++){
            if(get<1>(job[j]) <= get<0>(job[i])){
                maxprofit = max(maxprofit, profits[j] + get<2>(job[i]));
            }
        }
        if(maxprofit == 0){
            maxprofit = get<2>(job[i]);
        }
        cout << maxprofit << endl;
        profits.push_back(maxprofit);
    }
    int answer = -1;
    for(int i = 0; i<jobs; i++){
        if(answer == -1 || profits[i] > profits[answer]){
            answer = i;
        }
    }
    cout << profits[answer];
}