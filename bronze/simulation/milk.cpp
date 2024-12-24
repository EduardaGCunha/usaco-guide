#include <bits/stdc++.h>
using namespace std;

struct val{
    int a, c;
    string s;
};

int main(){
    int n; cin >> n;
    vector<val> v;
    for(int i = 0; i < n; i++){
        val cow;
        cin >> cow.a >> cow.s >> cow.c;
    }

    sort(v.begin(), v.end(), [&](val &a, val &b){return a.a < b.a;});
    int m = 7, e = 7, b = 7;
    int prev = 7;

    for(int i = 0; i < n; i++){
        if(v[i].s == "Mildred"){
            m += v[i].c;
        }else if(v[i].s == "Elsie"){
            e += v[i].c;
        }else b += v[i].c;

        int cur = max({m, e, b});
        if(cur != prev)
    }
}