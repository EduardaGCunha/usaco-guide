#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0, ans = 0;
    int res = 0;
    for(auto c : a){
        while(i+1 < m && b[i] < c) i++;
        if(i!= 0) j = i - 1;
        ans = max(ans, min(abs(b[i]-c), abs(b[j]-c)));
    }
    cout << ans << endl;
}