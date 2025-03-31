#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int dp[MAXN][MAXN];

int main(){
    int h, w; cin >> w >> h;

    for(int i = 0; i <= w; i++){
        for(int j = 0; j <= h; j++){
            if(i == j) continue;
            else{
                dp[i][j] = 1e9;
                for(int k = 0; k < i; k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] +dp[i-k][j]+1);
                }
                for(int k = 0; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]+1);
                }
            }
        }
    }

    cout << dp[w][h] << endl;
}