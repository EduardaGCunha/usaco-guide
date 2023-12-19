#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> quantity(3), capacity(3);
    freopen("mixmilk.in", "r", stdin);
    for(int i = 0; i < 3; i++){
        scanf("%d %d", &capacity[i], &quantity[i]);
    }

    for(int i = 0; i < 10; i++){
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
    freopen("mixmilk.out", "w", stdout);
    printf("%d\n%d\n%d\n", quantity[0], quantity[1], quantity[2]);
}