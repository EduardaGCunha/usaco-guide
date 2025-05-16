#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+7;
int p[MAXN], r[MAXN];

int find(int a){
    return (p[a] == a ? a : p[a] = find(p[a]));
}

void unite(int a, int b){
    a = find(a), b = find(b);
    if(r[a] == r[b]) r[a]++;
    if(r[a] > r[b]){
        p[b] = a;
        r[a] += r[b];
    }else{
        p[a] = b;
        r[b] += r[a];
    }
}

struct edges{
    int a, b, c, i; 
    bool operator < (const edges &x) const {
        return c > x.c;
    }
};

int main(){
    int n, m; cin >> n >> m;
    vector<edges> v;
    for(int i = 0; i < m; i++){
        
    }
}