#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n, t = 0; cin >> n;
    vector<pair<int ,int>> val;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        t+=a;
        val.push_back({a, b});
    }
    sort(val.begin(), val.end());

    int i = 0, j = n-1, ans = INT_MAX;


}