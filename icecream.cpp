#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long numbers[447]; 
    numbers[0] = 1;
    for(int i = 1; i<447; i++){
        numbers[i] = numbers[i-1] + i + 1;
    }
    cin >> t; 
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i<447; i++){
            if(numbers[i] > n){
                cout << i << endl;
                break;
            }
            else if (numbers[i] == n)
            {
                cout << i+1 << endl;
            }
            
        }
    }
}