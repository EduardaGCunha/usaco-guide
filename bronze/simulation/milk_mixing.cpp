#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> quantity(3), capacity(3);
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    for(int i = 0; i < 3; i++){
        cin >> capacity[i] >> quantity[i];
    }

    for(int i = 0; i < 4; i++){
        int x = i % 3, y = (x + 1) % 3;
        quantity[y] += quantity[x];
        if(quantity[y] > capacity[y]){
            int t = abs(capacity[y] - quantity[y]);
            quantity[y] -= t;
            quantity[x] = t;
        }else{
            quantity[x] = 0;
        }
    }
    cout << quantity[0] << endl << quantity[1] << endl << quantity[2] << endl;
}