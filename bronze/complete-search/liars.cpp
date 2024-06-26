#include <bits/stdc++.h>
using namespace std;


#define int long long

signed main(){
    int n; cin >> n;
    vector<int> g, l;

    for(int i = 0; i < n; i++){
        char a; int b; cin >> a >> b;
        if(a == 'G') g.push_back(b);
        else l.push_back(b);
    }

    sort(g.begin(), g.end());
    sort(l.begin(), l.end());
    int cnt = 0;
    for(auto a : l){
        auto b = upper_bound(g.begin(), g.end(), a)-g.begin();
        cnt += b;
    }

    cout << cnt << endl;
}