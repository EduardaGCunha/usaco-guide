#include <bits/stdc++.h>
using namespace std;

struct upd{
    int a, b;
    string s;
    bool operator<(const upd &other){
        return a < other.a;
    }
};

int main(){
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n; cin >> n;
    vector<upd> v;
    for(int i = 0; i < n; i++){
        upd x; cin >> x.a >> x.s >> x.b;
        //cout << x.a << " " << x.s << " " << x.b << endl;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    map<string, int> mp; 
    mp["Bessie"] = 7;
    mp["Elsie"] = 7;
    mp["Mildred"] = 7;
    int cnt = 0;
    vector<string> prev = {"Bessie", "Elsie", "Mildred"}; 
    for(int i = 0; i < n; i++){
        mp[v[i].s] += v[i].b;
        //cout << v[i].s << " " << v[i].b << endl;
        int mx = 0;
        vector<string> cur;
        for(auto u : mp) mx = max(u.second, mx);
        for(auto u : mp){
            if(u.second == mx) cur.push_back(u.first);
        }
        if(prev != cur) cnt++;
        prev = cur;
    }

    cout << cnt << endl;

}