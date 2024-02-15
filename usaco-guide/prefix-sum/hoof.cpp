#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n; cin >> n;
    vector<int> p(n+1, 0), h(n+1, 0), s(n+1, 0);
    for(int i = 1; i <= n; i++){
        char a; cin >> a;
        p[i] = p[i-1], s[i] = s[i-1], h[i] = h[i-1]; 
        if(a == 'P') p[i]++;
        else if(a == 'H') h[i]++;
        else s[i]++;
    }

    int ans = 0, b = 0, a = 0;
    for(int i = 1; i <= n; i++){
        int b = 0, a = 0;
        b = max({b, p[i], h[i], s[i]});
        a = max({a, p[n]- p[i], h[n] - h[i], s[n] - s[i]});
        ans = max(a+b, ans);
    }

    cout << ans<< endl;
}