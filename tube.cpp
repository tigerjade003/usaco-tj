#include <bits/stdc++.h>
using namespace std;
#define     mm(a, b)    make_tuple(a, b)

vector<tuple<int, int>> solve(string a, string b){
    int first = a[0] - '0';
    stack<int> a1;
    stack<int> b1;
    for(int i = 0; i<a.size(); i++){
        if(a1.empty() || a1.top() != a[i] - '0'){
            a1.push(a[i] - '0');
        }
        if(b1.empty() || b1.top() != b[i] - '0'){
            b1.push(b[i] - '0');
        }
    }
    int beaker = 0;
    vector<tuple<int, int>> ans;
    if(b1.top() == a1.top()){
        if(b1.size() < a1.size()){
            a1.pop();
            ans.push_back(mm(1, 2));
        }
        else{
            b1.pop();
            ans.push_back(mm(2, 1));
        }
    }
    if(b1.size() != 1 || a1.size() != 1){
        if(a1.size() > b1.size()){
            beaker = a1.top();
            a1.pop();
            ans.push_back(mm(1, 3));
        }
        else{
            beaker = b1.top();
            b1.pop();
            ans.push_back(mm(2, 3));
        }
        if(first != beaker){
            while(a1.size() > 1){
                if(a1.top() == b1.top()){
                    ans.push_back(mm(1, 2));
                }
                else{
                    ans.push_back(mm(1, 3));
                }
                a1.pop();
            }
            while(b1.size() > 1){
                if(b1.top() == a1.top()){
                    ans.push_back(mm(2, 1));
                }
                else{
                    ans.push_back(mm(2, 3));
                }
                b1.pop();
            }
        }
        else{
            while(b1.size() > 1){
                if(b1.top() == a1.top()){
                    ans.push_back(mm(2, 1));
                }
                else{
                    ans.push_back(mm(2, 3));
                }
                b1.pop();
            }
            while(a1.size() > 1){
                if(a1.top() == b1.top()){
                    ans.push_back(mm(1, 2));
                }
                else{
                    ans.push_back(mm(1, 3));
                }
                a1.pop();
            }
        }
        if(beaker == a1.top()){
            ans.push_back(mm(3, 1));
        }
        else{
            ans.push_back(mm(3, 2));
        }
    }
    return ans;
}

int t;
int main(){
    cin >> t;
    while(t--){
        int n, p;
        cin >> n >> p;
        string a;
        string b;
        cin >> a;
        cin >> b;
        vector<tuple<int, int>> l1 = solve("1" + a, "2" + b);
        vector<tuple<int, int>> l2 = solve("2" + a, "1" + b);
        if(l1.size() < l2.size()){
            cout << l1.size() << endl;
            if(p != 1){
                for(auto q: l1){
                    cout << get<0>(q) << " " << get<1>(q) << endl;
                }
            }
        }
        else{
            cout << l2.size() << endl;
            if(p != 1){
                for(auto q: l2){
                    cout << get<0>(q) << " " << get<1>(q) << endl;
                }
            }
        }
    }
    return 0;
}