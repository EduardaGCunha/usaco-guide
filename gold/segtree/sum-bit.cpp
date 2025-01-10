#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int bit[MAXN], n;

void update(int i, int x){
    for(; i <= n; i += (i&(-i))){
        bit[i] += x;
    }
}

int sum(int i){
    int sum = 0;
    for(; i <= n; i += (i&(-i))){
        sum += bit[i];
    }
    return sum;
}

void range(int a, int b){
    cout << sum(b) - sum(a-1) << endl;
}

int main(){
    int q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        update(i, x);
    }

    while(q--){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            update(b, c);
        }else{
            range(b, c);
        }
    }
}