#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 2*(1e5);
vector<int> arr(MAXN);
int pref[4*MAXN], suf[4*MAXN], sfx[MAXN];

int query(int v, int l, int r, int a, int b, int ar[]){
    if(b < l || r < a) return 0;
    if(a <= l && r <= b) return ar[v];
    int m = (l+r)/2;
    return query(2*v, l, m, a, b, ar) + query(2*v+1, m+1, r, a, b, ar);
}

void update(int v, int l, int r, int i, int x, int a[]){
    if(i < l || r < i) return;
    if(l == r){
        a[v] = x;
        return;
    }
    int m = (l+r)/2;
    update(2*v, l, m, i, x, a);
    update(2*v+1, m+1, r, i, x, a);
    a[v] = a[2*v] + a[2*v+1];
}

signed main(){
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    fastio;
    int n; cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> srt = arr;
    sort(srt.begin(), srt.end());
    for(int i = 0; i < n; i++){
        arr[i] = lower_bound(srt.begin(), srt.end(), arr[i]) - srt.begin();
    }

    for(int i = 0; i < n; i++){
        sfx[arr[i]] = query(1, 1, n, arr[i]+1, n, suf);
        update(1, 1, n, arr[i], 1, suf);
        //cout << arr[i] << " " << sfx[i] << endl;
    }

    reverse(arr.begin(), arr.end());
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int pfx = query(1, 1, n, arr[i]+1, n, pref);
        //cout << arr[i] << " caras na frente: " << pfx << " caras atras: " << sfx[i] << endl;
        update(1, 1, n, arr[i], 1, pref);
        if(min(pfx, sfx[arr[i]])*2 < max(pfx, sfx[arr[i]])) cnt++;
    }
    cout << cnt << endl;
    
}
