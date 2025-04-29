#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
const int INF = 1e18;

struct segtree {
    int n;
    vector<pair<int,int>> t;
    void init(int _n) {
        n = _n;
        t.assign(4*n, {-INF, INF});
    }

    void build(vector<pair<int,int>> &a, int v, int l, int r) {
        if (l == r) {
            t[v] = a[l];
            return;
        }
        int m = (l + r)/2;
        build(a, 2*v+1, l, m);
        build(a, 2*v+2, m+1, r);
        t[v].first  = max(t[2*v+1].first, t[2*v+2].first);
        t[v].second = min(t[2*v+1].second, t[2*v+2].second);
    }
    void build(vector<pair<int,int>> &a) {
        build(a, 0, 0, n-1);
    }

    pair<int,int> query(int v, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return {-INF, INF};
        if (ql <= l && r <= qr) return t[v];
        int m = (l + r)/2;
        auto L = query(2*v+1, l, m, ql, qr);
        auto R = query(2*v+2, m+1, r, ql, qr);
        return {max(L.first,  R.first), min(L.second, R.second)};
    }
    pair<int,int> query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }

    void update(int v, int l, int r, int idx, pair<int,int> x) {
        if (l == r) {
            t[v] = x;
            return;
        }
        int m = (l + r)/2;
        if (idx <= m) update(2*v+1, l, m, idx, x);
        else update(2*v+2, m+1, r, idx, x);
        t[v].first  = max(t[2*v+1].first,  t[2*v+2].first);
        t[v].second = min(t[2*v+1].second, t[2*v+2].second);
    }
    void update(int idx, pair<int,int> x) {
        update(0, 0, n-1, idx, x);
    }
};

signed main(){
    fastio;
    int n, q; cin >> n >> q;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    
    segtree st;
    st.init(n);
    st.build(arr);
    while(q--){
        char op; cin >> op;
        if(op == 'C'){
            int idx;
            pair<int, int> v;
            cin >> idx >> v.first >> v.second;
            idx--;
            st.update(idx, v);
        }else{
            int l, r; cin >> l >> r;
            l--, r--;
            pair<int, int> p = st.query(l, r);
            int ans = max(0LL, p.second - p.first + 1);
            cout << ans << endl;
        }
    }
}