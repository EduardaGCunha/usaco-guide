#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5);
int p[MAXN], sum[MAXN], r[MAXN];
int n, m;
int c, maxi;

int get(int a){
    return p[a] = (p[a] == a) ? a : get(p[a]);
}

void unite(int a, int b){
    a = get(a);
    b = get(b);

    if(a == b) return;

    if(r[a] == r[b]){
        r[a]++;
    }if(r[a] > r[b]){
        p[b] = a;
        sum[a] += sum[b];
    }else{
        p[a] = b;
        sum[b] += sum[a];
    }
    c--;
    maxi = max({sum[b], sum[a], maxi});
}

int main(){
    int n, m;
    cin >> n >> m;
    c = n, maxi = 0;
    for(int i = 0; i < n; i++){
        sum[i] = 1;
        p[i] = i;
        r[i] = 0;
    }
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        unite(a, b);
        cout << c << " " << maxi << endl;
    }
}