#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 2*(1e5);
int arr[MAXN];
pair<int, int> tree[4*MAXN];
int n;

void build(int v, int l, int r){
    if(l == r){
        tree[v] = {1, arr[l]};
        return;
    }
    int m = (l+r)/2;
    build(2*v, l, m);
    build(2*v+1, m+1, r);
    tree[v].first = tree[2 * v].first + tree[2 * v + 1].first;
}

void update(int v, int l, int r, int i){
    if(i < l || r < i) return;
    if(l == r){
        tree[v].first = 0;
        return;
    }
    int m = (l+r)/2;
    update(2*v, l, m, i);
    update(2*v+1, m+1, r, i);
    tree[v].first = tree[2*v].first + tree[2*v+1].first;
}


int find(int k, int x, int l, int r){
    if(l == r) return l;
    int m = (l + r)/2;
    int sl = tree[2*x].first;
    if(k < sl) return find(k, 2*x, l, m);
    else return find(k-sl, 2*x+1, m+1, r);
}

int find(int k){
    return find(k, 1, 0, n-1);
}


signed main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(1, 0, n-1);
    int q = n;
    while(q--){
        int k; cin >> k;
        k--;
        int idx = find(k);
        cout << arr[idx] << " ";
        update(1, 0, n-1, idx);
    }
    cout << endl;
    
}
