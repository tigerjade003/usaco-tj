#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int hours = stoi(s.substr(0, 2));
        int minutes = stoi(s.substr(3,4));
        if(hours < 10 && hours != 0){
            cout << "0";
        }
        if(hours > 12){
            if(hours - 12 < 10){
                cout << "0";
            }
            cout << (hours-12) << ":";
            if(minutes < 10){
                cout << "0";
            }
            cout << minutes << " PM";
        }
        else if(hours == 12){
            cout << hours << ":";
            if(minutes < 10){
                cout << "0";
            }
            cout << minutes << " PM";
        }
        else if(hours == 0){
            cout << 12 << ":";
            if(minutes < 10){
                cout << "0";
            }
            cout << minutes << " AM";
        }
        else{
            cout << hours << ":";
            if(minutes < 10){
                cout << "0";
            }
            cout << minutes << " AM";
        }
        cout << endl;
    }
}