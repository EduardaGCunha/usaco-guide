#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 501;
int p[MAXN], r[MAXN];
int n, m;
struct edge{
    int a, b;
    bool operator < (const edge &x) const {
        if(b == x.b) return a < x.a;
        return b < x.b;
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


signed main(){
    init();
    cin >> n;
    edge arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].a >> arr[i].b;
    }

    sort(arr, arr+n);

    for(int i = 0; i < n; i++){
        cout << arr[i].b << endl;
    }
    
}