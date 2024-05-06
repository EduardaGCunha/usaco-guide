#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;

int main(){
    int n; cin >> n;
    int arr[n+1];
    bool dp[MAXN][MAXN];

    int w = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        w += arr[i];
    }
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = dp[i-1][j];
            if(j - arr[i] >= 0 && dp[i-1][j-arr[i]]){
                dp[i][j] = true;
            }   
        }
    }

}