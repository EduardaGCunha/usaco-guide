#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 505;
vector<int> groups[MAXN];
int cost[MAXN][MAXN], dp[MAXN][MAXN];

void solve(){
    int n, m, l; cin >> n >> m >> l;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        groups[i%l].push_back(x);
    }

    //custo p/ transformar o grupo i no remainder L;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < m; j++){
            int c = 0;
            for(auto u : groups[i]){
                int cur = (u%m);
                if(cur > j) c += (m + j - cur);
                else c += (j - cur);
            }
            cost[i][j] = c;
        }
    }

    for (int i = 0; i <= l; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    /*
    qual o custo pra transformar os iesimos primeiro grupos no remainder R?
    */
    //iesimos grupos
    for(int i = 0; i < l; i++){

        for(int j = 0; j < m; j++){//olhando pra previous remainder sum
            if(dp[i][j] == 1e18) continue;

            //eh possivel usar essa remainder sum, entao quais sao todos os remainders q eu consigo construir?
            for(int k = 0; k < m; k++){
                int rem = (j+k)%m;
                //qual o custo p/ transformar esse iesimo grupo nesse remainder rem?
                int custo = cost[i][k];

                dp[i+1][rem] = min(dp[i+1][rem], dp[i][j] + custo);
            }
        }
    }

    cout << dp[l][0] << endl;
}

signed main(){
	fastio;
    int t;
    t = 1;
	while(t--){
		solve();
	}
}