#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
 
const int MAXN = 2*(1e5)+7;
const int MAXL = 20;
int up[MAXN][MAXL+1];
int main(){
    fastio;
    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++){
        cin >> up[i][0];
    }
    //cout << "passou da leitura\n";
 
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= MAXL; j++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    
    while(q--){
        int a, b; cin >> a >> b;
        for(int i = 0; i < MAXL; i++){
            if(b&(1<<i)){
                a = up[a][i];
            }
        }
        if(a == 0) a = -1;
        cout << a << endl;
    }
 
}