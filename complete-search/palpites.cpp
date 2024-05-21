#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

int n;
const int MAXN = 1e5;
int p[MAXN], e[MAXN];
multiset<int> ms;

int check(int x){
    for(int i = 0; i < n; i++){
        if(ms.count(abs(x-p[i])) == 0) return 0;
    }
    return 1;
}

signed main(){
    fastio;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++){
        cin >> e[i];
        ms.insert(e[i]);
    }
    sort(p, p+n);
    set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(abs(p[n-1]-e[i]));
        s.insert(p[n-1]+e[i]);
    }

    for(auto a : s){
        if(a > 1e9 || a <= 0) continue;
        if(check(a)) cout << a << '\n';
    }
}