#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 262148;
int arr[MAXN], dp[MAXN];

int dynamic(int i, int t){
    if(i > t) return 0;
    if(dp[i] != -1) return dp[i];
    dp[i] = max(dynamic(2*i, t)+arr[i], dynamic(2*i+1, t)+arr[i]);
    return dp[i];
}

signed main(){
    int n; cin >> n;
    int t = pow(2, n);
    for(int i = 1; i < t; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < t; i++){
        dp[i] = -1;
    }
    cout <<  dynamic(1, t) << endl;
}