#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n; cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        pq.push(a);
    }

    int i = 0, ans = 0;
    while(i < n){
        int a = pq.top(); pq.pop();
        if(a >= i) ans++;
        i++;
    }

    cout << ans << endl;
}