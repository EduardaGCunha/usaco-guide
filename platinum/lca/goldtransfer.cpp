#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define int long long

const int MAXL = 20;
const int MAXN = 1e6+7;
int depth[MAXN], cost[MAXN], amount[MAXN];
int anc[MAXN][MAXL];

signed main(){
    int q; cin >> q;
    cin >> amount[0] >> cost[0];

    for(int i = 1; i <= q; i++){
        int tipo; cin >> tipo;
        if(tipo == 1){
            int p, a, c; cin >> p >> amount[i] >> cost[i];
            anc[i][0] = p;

            for(int j = 1; j < MAXL; j++){
                anc[i][j] = anc[anc[i][j-1]][j-1];
            }
        }else{
            int v, w; cin >> v >> w;
            int qtd = 0, p = 0;
            while(w > 0){
                int u = v;
                for (int j = MAXL-1; j >= 0; j--){
                    if (anc[u][j] != -1 && amount[anc[u][j]] > 0)
                        u = anc[u][j];
                }
                if (amount[u] == 0)
                    break;
                int mn = min(w, amount[u]);
                amount[u] -= mn;
                w -= mn;
                qtd += mn;
                p += mn * cost[u];
            }
            

            cout << qtd << " " << p << endl;
        }
    }
}