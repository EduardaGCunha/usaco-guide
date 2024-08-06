#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3*(1e5)+7;
int p[MAXN], r[MAXN], mini[MAXN], maxi[MAXN], sum[MAXN];

int get(int a){
    //if a is not it's parent, return the p[a]
    return p[a] = (p[a] == a ? a : get(p[a]));
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
        mini[a] = min(mini[a], mini[b]);
        maxi[a] = max(maxi[a], maxi[b]);
    }else {
        p[a] = b;
        mini[b] = min(mini[a], mini[b]);
        maxi[b] = max(maxi[a], maxi[b]);
        sum[b] += sum[a];
    }
}

int main(){
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++){
        r[i] = 0;
        p[i] = i;
        mini[i] = i;
        maxi[i] = i;
        sum[i] = 1;
    }

    for(int i = 0; i < m; i++){
        string s; cin >> s;
        if(s == "union"){
            int a, b; cin >> a >> b;
            unite(a, b);
        }
        else{
            int a; cin >> a;
            a = get(a);
            cout << mini[a] << " " << maxi[a] << " " << sum[a] << endl;
        }
    }
}