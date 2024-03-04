#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int x, n; cin >> x >> n;
    set<int> s; multiset<int> ms;
    s.insert(0), s.insert(x);
    ms.insert(x);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        auto it1 = s.lower_bound(a);
        auto it2 = it1; it2--;
        ms.erase(ms.find(*it1 - *it2));
        ms.insert(*it1 - a);
        ms.insert(a - *it2);
        s.insert(a);
        auto ans = ms.end();
        --ans;
        cout << *ans << endl;
    }
}