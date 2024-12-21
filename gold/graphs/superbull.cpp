#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int p[MAXN], r[MAXN], n;

#define int long long

void init(){
    for(int i = 1; i <= 2000; i++){
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

struct edges{
    int a, b, c;
};

signed main(){
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<edges> v;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            v.push_back({i, j, (arr[i]^arr[j])});
            cnt++;
        }
    }

    init();


    sort(v.begin(), v.end(), [&](edges &a, edges &b) {return a.c > b.c;});

    int ans = 0, j = 0;
    for(int i = 0; i < cnt; i++){
        edges r = v[i];
        //cout << r.a << " " << r.b << " " << r.c << endl;
        if(find(r.a) != find(r.b)){
            unite(r.a, r.b);
            //cout << r.a << " " << r.b << " " << r.c << endl;
            ans += r.c;
            j++;
            if(j == n-1){
                cout << ans << endl;
                return 0;
            }
        }
    }
}