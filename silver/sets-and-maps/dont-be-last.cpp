#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int n; cin >> n;
    map<string, int> m;
    int minimum = INT_MAX;
    for(int i = 0; i < n; ++i){
        string a; int b; cin >> a >> b;
        m[a] += b;
    }

    if((int)m.size() < 7){
        minimum = 0;
    }else{
        for(auto & a : m) minimum = min(minimum, a.second);
    }

    string ans = "";
    int secmin = INT_MAX, cnt = 0;
    for(auto & a : m){
        if(a.second > minimum && a.second < secmin){
            secmin = a.second;
            ans = a.first;
            cnt = 1;
        }else if(a.second == secmin) cnt++;
    }

    cout << (cnt == 1 ?  ans : "Tie" )<< endl;

}