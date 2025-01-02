#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5;
int n;
int arr[MAXN], dp[MAXN];

int dynamic(int i){
    if(i == n) return arr[i];
    if(i > n) return INT_MIN;
    if(dp[i] != -1) return dp[i];
    dp[i] = max(dynamic(i+1)+arr[i], dynamic(i+2)+arr[i]);
    return dp[i];
}

signed main(){
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    cin >> n; 
    for(int i = 1; i <= n; i++) cin >> arr[i];
    arr[0] = 0;
    for(int i = 0; i < 1e5; i++) dp[i] = -1;
    cout << dynamic(0) << endl;
}