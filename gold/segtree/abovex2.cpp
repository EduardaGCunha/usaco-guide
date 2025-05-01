#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

struct segtree{
    int n;
    vector<int> t;
    void init(int _n){
        n = _n;
        t.assign(4*n, 0);
    }

    void build(vector<int> &arr, int v, int l, int r){
        if(l == r){
            t[v] = arr[l];
            return;
        }

        int m = (l+r)/2;
        build(arr, 2*v+1, l, m);
        build(arr, 2*v+2, m+1, r);
        t[v] = op(t[2*v+1], t[2*v+2]);
    }

    void build(vector<int> &arr){
        build(arr, 0, 0, n-1);
    }

    int op(int a, int b){
        return max(a, b);
    }

    int query(int v, int l, int r, int lx, int rx){
        if(l > rx || r < lx) return 0;
        if(lx <= l && r <= rx) return t[v];
        int m = (l+r)/2;
        return op(query(2*v+1, l, m, lx, rx), query(2*v+2, m+1, r, lx, rx));
    }

    int query(int l, int r){
        return query(0, 0, n-1, l, r);
    }

    void update(int v, int l, int r, int idx, int val){
        if(l == r){
            t[v] = val;
            return;
        }
        int m = (l+r)/2;
        if(idx <= m) update(2*v+1, l, m, idx, val);
        else update(2*v+2, m+1, r, idx, val);
        t[v] = op(t[2*v+1], t[2*v+2]);
    }

    void update(int idx, int val){
        update(0, 0, n-1, idx, val);
    }

    int find(int v, int l, int r, int k, int lx) {
        if (r < lx || t[v] < k) return -1;
        if (l == r) return l;
        int m = (l+r)/2;
        int res = find(2*v+1, l, m, k, lx);
        if (res != -1) return res;
        return find(2*v+2, m+1, r, k, lx);
    }

    int find(int k, int l){
        return find(0, 0, n-1, k, l);
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
    while(q--){
        int op; cin >> op;
        op--;
        if(!op){
            int idx, val; cin >> idx >> val;
            st.update(idx, val);
            //arr[idx] = !arr[idx];
        }else{
            int k, l; cin >> k >> l;
            //if(st.query(0, n-1) < k) cout << -1 << endl;
            cout << st.find(k, l) << endl;
        }
    }
}