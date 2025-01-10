#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 2*(1e5);
vector<int> arr(MAXN);
int sfx[MAXN], pfx[MAXN];

struct segtree{
    vector<int> ar;
    void init(int n){
        ar.resize(4*n);
        for(int i = 0; i < 4*n; i++) ar[i] = 0;
    }
    int query(int v, int l, int r, int a, int b){
        if(b < l || r < a) return 0;
        if(a <= l && r <= b) return ar[v];
        int m = (l+r)/2;
        return query(2*v, l, m, a, b) + query(2*v+1, m+1, r, a, b);
    }

    void update(int v, int l, int r, int i, int x){
        if(i < l || r < i) return;
        if(l == r){
            ar[v] += x;
            return;
        }
        int m = (l+r)/2;
        update(2*v, l, m, i, x);
        update(2*v+1, m+1, r, i, x);
        ar[v] = ar[2*v] + ar[2*v+1];
    }
};


signed main(){
    fastio;
    int n; cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    segtree seg1, seg2;
    seg1.init(n);
    seg2.init(n);

    for(int i = 0; i < n; i++){
        pfx[i] = seg1.query(1, 1, n, arr[i]+1, n);
        seg1.update(1, 1, n, arr[i], 1);
    }

    int cnt = 0;
    for(int i = n-1; i >=0; i--){
        sfx[i] = seg2.query(1, 1, n, 1, arr[i]-1);
        seg2.update(1, 1, n, arr[i], 1);
        cnt += pfx[i]*sfx[i];
    }
    cout << cnt << endl;
    
}
