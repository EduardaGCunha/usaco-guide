#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("pcb.in", "r", stdin);
    //freopen("pcb.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        v[i].second *=-1;
    }

    sort(v.begin(), v.end()); 

    vector<int> dp;

    for(int i = 0; i < n; i++){
        int pos = lower_bound(dp.begin(), dp.end(), v[i].second) - dp.begin();
        if(pos == dp.size()){
            dp.push_back(v[i].second);
        }else{
            dp[pos] = v[i].second;
        }
    }

    cout << dp.size() << endl;
}