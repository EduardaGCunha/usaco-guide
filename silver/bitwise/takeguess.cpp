#include <bits/stdc++.h>
using namespace std;

#define int long long

int q(int i, int j){
    cout << "and " << i << " " << j << endl;
    int x; cin >> x;
    cout << "or " << i << " " << j << endl;
    int y; cin >> y;
    return x + y;
}

signed main(){
    int n, k; cin >> n >> k;
    vector<int> ans(n);
    int a = q(1, 2);
    int b = q(1, 3);
    int c = q(2, 3);

    ans[0] = (a+b-c)/2;
    ans[1] = a - ans[0];
    ans[2] = c - ans[1];

    for(int i = 3; i < n; ++i){
        ans[i] = q(i, i+1) - ans[i-1];
    }

    sort(ans.begin(), ans.end());
    cout << "finish " << ans[k-1] << endl;
    return 0;
}