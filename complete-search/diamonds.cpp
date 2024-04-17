#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector<int> val(n);
    for(int i = 0; i < n; i++) cin >> val[i];
    sort(val.begin(), val.end());

    int cnt = 1, mx = 1;
    for(int i = 0; i < n - 1; i++){
        cnt = 1;
        for(int j = i + 1; j < n; j++)
            if(abs(val[j] - val[i]) <= k) cnt++;
        mx = max(mx, cnt);
    }

    cout << mx << endl;

}
