#include <bits/stdc++.h>
using namespace std;

#define int long long
/*
passos
cria uma segtree inicialmente vazia com 0
vai colocando com 1 todo cara q eu visitar
se eu encontrar um cara q ja foi visitado
    faco uma query pra descobrir quem eh o valor e somo na resposta

*/

struct segtree {
    int n;
    vector<int> t;
    void init(int _n) {
        n = _n;
        t.assign(4*n, 0);
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
    int n; cin >> n;
    n = 2*n;
    segtree st;
    st.init(n);
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> visited(n+1, -1);
    vector<int> ans((n/2)+1);
    for(int i = 0; i < n; i++){
        if(visited[arr[i]] != -1){
            ans[arr[i]] = st.query(visited[arr[i]]+1, i-1);
            st.update(visited[arr[i]], 0);
        }else{
            visited[arr[i]] = i;
            st.update(i, 1);
        }
    }

    for(int i = 0; i < n/2; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}