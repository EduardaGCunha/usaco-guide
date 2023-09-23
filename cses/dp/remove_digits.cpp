#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int BIG_NUMBER = 1e9;
    vector<int> dp(n+1, BIG_NUMBER);

    dp[0] = 0;

    for(int i = 1; i < n + 1; i++){
        int num = i;
        while(num > 0){
            int digit = num % 10;
            dp[i] = min(dp[i], 1 + dp[i - digit]);
            num/=10;
        }
    }

    cout << dp[n] << endl;
}