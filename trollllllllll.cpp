//a+b+((a2+b2)+(a−b)+|a|×2b−(ab+2))
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    string str2;
    cin >> str2;
    string str3;
    cin >> str3;
    int a = stoi(str);
    int b = stoi(str3);
    cout << (a+b+(pow(a,2) + pow(b, 2) + (a-b) + abs(a)*2*b -(a*b+2)));
}