#include <bits/stdc++.h>
using namespace std;

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
        t[v] = t[2*v+1] + t[2*v+2];
    }

    void build(vector<int> &arr){
        build(arr, 0, 0, n-1);
    }

    int query(int v, int l, int r, int lx, int rx){
        if(l > rx || r < lx) return 0;
        if(lx <= l && r <= rx) return t[v];
        int m = (l+r)/2;
        return query(2*v+1, l, m, lx, rx) + query(2*v+2, m+1, r, lx, rx);
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
        t[v] = t[2*v+1] + t[2*v+2];
    }

    void update(int idx, int val){
        update(0, 0, n-1, idx, val);
    }

    int find(int v, int l, int r, int k){
        if(l == r) return l;
        int m = (l+r)/2;
        if(t[2*v+1] > k) return find(2*v+1, l, m, k);
        else return find(2*v+2, m+1, r, k - t[2*v+1]);
    }

    int find(int k){
        return find(0, 0, n-1, k);
    }
};

signed main(){
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
            int idx; cin >> idx;
            st.update(idx, !arr[idx]);
            arr[idx] = !arr[idx];
        }else{
            int k; cin >> k;
            cout << st.find(k) << endl;
        }
    }
}