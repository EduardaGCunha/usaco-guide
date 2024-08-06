#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5)+7;
int p[MAXN], r[MAXN], sum[MAXN], x[MAXN];

int get(int a){
    //if a is not it's parent, return the p[a]
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void add(int a, int b){
    a = get(a);
    x[a] += b;
}

void unite(int a, int b){
    //getting their father
    a = get(a);
    b = get(b);

    if(a == b) return;
    if(r[a] == r[b]){
        r[a]++;
    }if(r[a] > r[b]){
        p[b] = a;
        sum[a] += sum[b];
    }else {
        p[a] = b;
        sum[b] += sum[a];
    }
}

int main(){
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++){
        r[i] = 0;
        p[i] = i;
        x[i] = 0;
        sum[i] = 1;
    }

    for(int i = 0; i < m; i++){
        string s; cin >> s;
        if(s == "join"){
            int a, b; cin >> a >> b;
            unite(a, b);
        }
        else if(s == "get"){
            int a; cin >> a;
            a = get(a);
            cout << x[a] << endl;
        }else{
            int a, b; cin >> a >> b;
            add(a, b);
        }
    }
}