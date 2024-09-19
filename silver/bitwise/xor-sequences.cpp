#include <bits/stdc++.h>
using namespace std;

int main(){
    int x; cin >> x;
    for(int i = 0; i < 7; i++){
        int a = x ^ i;
        cout << a << endl;
    }
}