#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int n; cin >> n;
    vector<int> values(n);
    for(int i = 0; i < n; i++) cin >> values[i];

    map<int, int> dp;

    int ans = 0; 
    int lst = 0;
    for(int i = 0; i < n; i++){
        int x = values[i];
        dp[x] = dp[x - 1] + 1;
        if(ans < dp[x]){
            ans = dp[x];
            lst = x;
        }
    }

    vector<int> res;
    for(int i = n - 1; i >= 0; i--){
        if(values[i] == lst){
            res.push_back(i);
            lst--;
        }
    }

    cout << ans << endl;
    sort(res.begin(), res.end());
    for(auto r : res) cout << r + 1 << " ";
    cout << endl;
}