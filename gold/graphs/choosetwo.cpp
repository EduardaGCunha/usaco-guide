#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 501;
int p[MAXN], r[MAXN];
int n, m;
struct edge{
    int a, b, c;
    bool operator < (const edge &x) const {
        return c > x.c;
    }
};

void init(){
    for(int i = 0; i < MAXN; i++){
        p[i] = i;
        r[i] = 1;
    }
}

int find(int a){
    return p[a] == a? a : p[a] = find(p[a]); 
}

bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if (r[a] < r[b]) swap(a, b);
    p[b] = a;
    if(r[a] == r[b]) r[a]++;
    return true;
}

int fastexpo(int a, int b){ 
    int res = 1;
    a%=m;
    while(b){
        if(b&1) res = (res*a)%m;
        a = (a*a)%m;
        b/=2;
    }
    return res;
}


signed main(){
    init();
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<edge> edges;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(i == j) continue;
            int calc = (fastexpo(arr[i], arr[j]) + fastexpo(arr[j], arr[i]))%m;
            edges.push_back({i, j, calc});
        }
    }

    sort(edges.begin(), edges.end());
    int ans = 0;
    for(auto u : edges){
        if(unite(u.a, u.b)){
            ans += u.c;
        }
    }
    cout << ans << endl;
}