#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int r[MAXN], p[MAXN], n, m;

#define int long long 
struct graph{
    int a, b, c;
};

void init(){
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
}

int find(int a){
    return (p[a] == a ? a : p[a] = find(p[a]));
}

void unite(int a, int b){
    int x = find(a), y = find(b);

    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]){
        p[y] = x;
        r[x]++;
    }else{
        p[x] = y;
        r[y]++;
    }
}

signed main(){
    cin >> n >> m;
    vector<graph> v;
    for(int i = 0; i < m; i++){
        graph r; cin >> r.a >> r.b >> r.c;
        r.a--, r.b--;
        v.push_back(r);
    }

    sort(v.begin(), v.end(), [&](graph &a, graph &b){ return a.c < b.c;});
    init();

    int ans = 0, cnt = 0;
    for(int i = 0; i < m; i++){
        graph r = v[i];
        //cout << r.a << " " << r.b << " " << r.c << endl;
        if(find(r.a) != find(r.b)){
            unite(r.a, r.b);
            ans += r.c;
            cnt++;
        }
    }

    if(cnt < n-1) cout << "IMPOSSIBLE\n";
    else cout << ans << endl;

    
}