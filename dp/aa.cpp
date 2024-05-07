#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3; 
//const int MAXSUM = 1e5;

int main(){
    //freopen("text2.txt", "r", stdin);
    int n, w = 0; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        w += arr[i];
    }   
    //cout << w << endl;

    vector<vector<bool>> dp (n+1, vector<bool>(w+1));
 
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = dp[i-1][j];
            int x = j - arr[i-1];
            if(x >= 0 && dp[i-1][x]) dp[i][j] = true;
        }
    }

    vector<int> v;
    for(int i = 1; i <= w; i++){
        if(dp[n][i]) v.push_back(i);
    }

    cout << v.size() << endl;
    for(auto a : v) cout << a << " ";
    cout << endl;
} 