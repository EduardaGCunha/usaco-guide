#include <bits/stdc++.h>
using namespace std; 

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define int long long

const int INF = 1e18;
const int MAXM =1e5+7;
const int MAXN = 101;
int peso[MAXN], val[MAXN];
//posicao, peso
int dp[MAXN][MAXM];

int n, k;
int pd(int w, int i){
    if(w > k) return -INF;
    if(i == n) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    return dp[i][w] = max(pd(w+peso[i], i+1) + val[i], pd(w, i+1));
}

signed main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> peso[i] >> val[i];
    }

    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXM; j++){
            dp[i][j] = -1;
        }
    }

    cout << pd(0, 0) << endl;
}