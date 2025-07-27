#include <bits/stdc++.h>
using namespace std;

int f(int x, int y){
    if(x >= 10){
        return (2 * f(x-2, y-3)) + 1;
    }
    else if(x < 10 && x > 4){
        return f(y-1, x-3) - 1;
    }
    else if(x <= 4){
        return x*y;
    }
    return -1;
}

int main(){
    cout << f(15, 11);
}