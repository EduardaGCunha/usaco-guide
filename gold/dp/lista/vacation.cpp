#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int dp[MAXN][3];
int arr[MAXN][3];

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) cin >> arr[i][j];
    }

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for(int i = 1; i < n; i++){
                    //manter, pegar ele + o segundo, pegar ele + o terceiro anterior
        dp[i][0] = max(arr[i][0] + dp[i-1][1], arr[i][0] + dp[i-1][2]);
        dp[i][1] = max(arr[i][1] + dp[i-1][0], arr[i][1] + dp[i-1][2]);
        dp[i][2] = max(arr[i][2] + dp[i-1][0], arr[i][2] + dp[i-1][1]);
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}
