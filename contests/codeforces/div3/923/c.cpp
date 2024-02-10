#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        unordered_map<int, int> a, b;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a[x]++;
        }
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            b[x]++;
        }

        int ans = 0, a_cnt =0, b_cnt =0;
        for(int i = 1; i <= k; i++){
            if(a[i] && b[i]) ans++;
            else if(a[i]) a_cnt++;
            else if(b[i]) b_cnt++;
        }

        string res = "YES";
        if(a_cnt + b_cnt + ans != k || a_cnt > k/2 || b_cnt > k/2){
            res = "NO";
        }
        cout << res << endl;
    
    }

}