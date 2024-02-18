#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> s, e; 
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        s.push_back({a, c});
        e.push_back({b, c});
    }

    sort(s.begin(), s.end());
    sort(e.begin(), e.end());
}