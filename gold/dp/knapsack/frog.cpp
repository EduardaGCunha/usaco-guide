#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

int n;
const int MAXN = 1e5;
int arr[MAXN], dp[MAXN];

int dynamic(int i){
    if(i == n - 1) return 0;
    if(i > n) return INT_MAX;
    if(dp[i] != -1) return dp[i];
    dp[i] = min(dynamic(i+1) + abs(arr[i] - arr[i+1]), dynamic(i+2) + abs(arr[i] - arr[i+2]));
    return dp[i];
}

signed main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < 1e5; i++) dp[i] = -1;
    cout << dynamic(0) << endl;
}