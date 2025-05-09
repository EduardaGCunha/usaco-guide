#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 2*(1e5);
int arr[MAXN], tree[4*MAXN];

int build(int v, int l, int r){
    if(l == r) return tree[v] = arr[l];
    int m = (l+r)/2;
    int b1 = build(2*v, l, m);
    int b2 = build(2*v+1, m+1, r);
    return tree[v] = min(b1, b2);
}

int query(int v, int l, int r, int a, int b){
    if(b < l || r < a) return INT_MAX;
    if(a <= l && r <= b) return tree[v];
    int m = (l+r)/2;
    int q1 = query(2*v, l, m, a, b);
    int q2 = query(2*v+1, m+1, r, a, b);
    return min(q1, q2);
}

void update(int v, int l, int r, int i, int x){
    if(i < l || r < i) return;
    if(l == r){
        tree[v] = x;
        return;
    }
    int m = (l+r)/2;
    update(2*v, l, m, i, x);
    update(2*v+1, m+1, r, i, x);
    tree[v] = min(tree[2*v], tree[2*v+1]);
}

signed main(){
    fastio;
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(1, 0, n-1);
    while(q--){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            b--;
            update(1, 0, n-1, b, c);
        }else{
            b--, c--;
            cout << query(1, 0, n-1, b, c) << endl;
        }
    }
}
