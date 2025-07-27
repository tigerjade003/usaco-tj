#include <bits/stdc++.h>
using namespace std;

int f(int x){
    if(x >= 12){
        return f(x-4)-3;
    }
    else if(x > 6){
        return f(x-3)+2;
    }
    else{
        return x*x;
    }
}

int main(){
    cout << f(f(20));
}