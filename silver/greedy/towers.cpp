#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    int n; cin >> n;
    vector<stack<int>> v;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    multiset<int> m;   
    int ans = 0; 
    for(int i = 0; i < n; i++){
        auto it = m.upper_bound(arr[i]);
        if(it != m.end()){
            m.erase(it);
        }else{
            ans++;
        }
        m.insert(arr[i]);
    }
    cout << ans << endl;
} 