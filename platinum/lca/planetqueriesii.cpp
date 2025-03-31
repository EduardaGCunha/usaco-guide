#include <bits/stdc++.h>
using namespace std;

const int MAXL = 20;
const int MAXN = 1e5+7;
int up[MAXN][MAXL];

int main(){
    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++){
        cin >> up[i][0];
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= MAXL; j++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while(q--){
        
    }
}