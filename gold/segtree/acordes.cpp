#include <bits/stdc++.h>
using namespace std;

#define int long long

struct segtree {
    int n;
    vector<int> t;
    vector<int> lazy;
    void init(int _n) {
        n = _n;
        t.assign(4*n, 1);
        lazy.assign(4*n, 0);
        vector<int> arr(n, 1);
        build(arr);
    }

    void propagate(int v, int l, int r){
        if(lazy[v] != 0){
            t[v] += (r - l + 1)*lazy[v];
            if(l != r){
                lazy[2*v+1] += lazy[v];
                lazy[2*v+2] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void updateRange(int v, int l, int r, int lx, int rx, int x){
        propagate(v, l, r);
        if(rx < l || r < lx) return;
        if(lx <= l && r <= rx){
            lazy[v] += x;
            propagate(v, l, r);
            return;
        }

        int m = (l+r)/2;
        updateRange(2*v+1, l, m, lx, rx, x);
        updateRange(2*v+2, m+1, r, lx, rx, x);
        t[v] = t[2*v+1] + t[2*v+2];
    }

    int queryRange(int v, int l, int r, int lx, int rx){
        propagate(v, l, r);
        if(rx < l || r < lx) return 0;
        if(lx <= l && r <= rx) return t[v];
        int m = (l+r)/2;
        return query(2*v+1, l, m, lx, rx) + query(2*v+2, m+1, r, lx, rx);
    }

    void build(vector<int> &a, int v, int l, int r) {
        if (l == r) {
            t[v] = a[l];
            return;
        }
        int m = (l + r)/2;
        build(a, 2*v+1, l, m);
        build(a, 2*v+2, m+1, r);
        t[v] = t[2*v+1] + t[2*v+2];
    }
    void build(vector<int> &a) {
        build(a, 0, 0, n-1);
    }

    int query(int v, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return t[v];
        int m = (l + r)/2;
        return query(2*v+1, l, m, ql, qr) + query(2*v+2, m+1, r, ql, qr);
    }
    int query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }

    void update(int v, int l, int r, int idx, int x) {
        if (l == r) {
            t[v] = x;
            return;
        }
        int m = (l + r)/2;
        if (idx <= m) update(2*v+1, l, m, idx, x);
        else update(2*v+2, m+1, r, idx, x);
        t[v] = t[2*v+1] + t[2*v+2];
    }
    void update(int idx, int x) {
        update(0, 0, n-1, idx, x);
    }
};

signed main(){
    //inicialmente, tudo tem 1
    
}