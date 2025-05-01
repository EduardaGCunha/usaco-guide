#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

struct segtree{
    int n;
    vector<int> sum, pref, suf, seg;

    void init(int _n){
        n = _n;
        sum.assign(4*n, 0);
        pref.assign(4*n, 0);
        suf.assign(4*n, 0);
        seg.assign(4*n, 0);
    }

    void build(vector<int> &arr, int v, int l, int r){
        if(l == r){
            sum[v] = arr[l];  
            pref[v] = max(arr[l], 0LL);
            suf[v]  = max(arr[l], 0LL);
            seg[v]  = max(arr[l], 0LL);
            return;
        }

        int m = (l+r)/2;
        build(arr, 2*v+1, l, m);
        build(arr, 2*v+2, m+1, r);
        sum[v] = sum[2*v+1] + sum[2*v+2];
        pref[v] = max(pref[2*v+1], pref[2*v+2] + sum[2*v+1]);
        suf[v] = max(suf[2*v+2], suf[2*v+1] + sum[2*v+2]);
        seg[v] = max({seg[2*v+1], seg[2*v+2], suf[2*v+1] + pref[2*v+2]});
    }

    void build(vector<int> &arr){
        build(arr, 0, 0, n-1);
    }

    int query(int v, int l, int r, int lx, int rx){
        //completamente fora
        if(l > rx || lx > r) return 0;
        if(lx <= l && r <= rx) return seg[v];
        int m = (l+r)/2;
        return max(query(2*v+1, l, m, lx, rx), query(2*v+2, m+1, r, lx, rx));
    }

    int query(){
        return query(0, 0, n-1, 0, n-1);
    }

    void update(int v, int l, int r, int idx, int x){
        if(l == r){
            sum[v] = x;
            pref[v] = max(x, 0LL);
            suf[v]  = max(x, 0LL);
            seg[v]  = max(x, 0LL);
            return;
        }
        int m = (l+r)/2;
        if(idx <= m) update(2*v+1, l, m, idx, x);
        else update(2*v+2, m+1, r, idx, x);
        sum[v] = sum[2*v+1] + sum[2*v+2];
        pref[v] = max(pref[2*v+1], pref[2*v+2] + sum[2*v+1]);
        suf[v] = max(suf[2*v+2], suf[2*v+1] + sum[2*v+2]);
        seg[v] = max({seg[2*v+1], seg[2*v+2], suf[2*v+1] + pref[2*v+2]});
    }

    void update(int idx, int val){
        update(0, 0, n-1, idx, val);
    }
};

signed main(){
    fastio;
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    segtree st;
    st.init(n);
    st.build(arr);
    cout << st.query() << endl;
    while(q--){
        int i, v; cin >> i >> v;
        //i--;
        st.update(i, v);
        cout << st.query() << endl;
    }

}