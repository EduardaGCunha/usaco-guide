#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5)+7;
int p[MAXN], r[MAXN];

int get(int a){
    return p[a] = (p[a] == a)? a : get(p[a]);
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(r[a] == r[b]){
        r[a]++;
    }if(r[a] > r[b]) p[b] = a;
    else p[a] = b;
}

int main(){
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        r[i]= 0;
        p[i] = i;
    }

    for(int i = 0; i < q; i++){
        int t, u, v; cin >> t >> u >> v;
        if(t == 1){
            if(get(u) == get(v)) cout << 1 << endl;
            else cout << 0 << endl;
        }else{
            unite(u, v);
        }
    }
}