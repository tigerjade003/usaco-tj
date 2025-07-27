#include <bits/stdc++.h>
using namespace std;

int main(){
    int d;
    cin >> d;
    string s;
    cin >> s;
    if(s == "DECREMENT"){
        d--;
    }
    else if(s == "INCREMENT"){
        d++;
    }
    cout << d << endl;
}