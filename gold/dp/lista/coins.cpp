#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3*(1e3)+7;
int n;
double heads[MAXN], tails[MAXN];
double dp[MAXN][MAXN];

double pd(int h, int t, double cur, int idx){
    if(h + t == n){
        if(h > t) return cur;
        else return 0;
    }


    return dp[h][t] = pd(h+1, t, cur * heads[idx], idx+1) + pd(h, t+1, cur * tails[idx], idx+1);
}

int main(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        cin >> heads[i];
        tails[i] = 1 - heads[i];
    }

    cout << pd(0, 0, 1, 0) << endl;
}