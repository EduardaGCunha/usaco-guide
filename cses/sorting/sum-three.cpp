#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long


signed main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> val;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        val.push_back({a, i+1}); 
    }

    sort(val.begin(), val.end());
    for(int i = 0; i < n; i++){
        int left = i+1,right = n - 1;
        while(left < right && right > i){
            //cout << val[left].second << " " << val[right].second << " " << val[i].second << endl;
            if(val[left].first + val[right].first + val[i].first == m){
                cout << val[left].second << " " << val[right].second << " " << val[i].second << endl;
                return 0;
            }
            else if(val[left].first + val[right].first + val[i].first < m) left++;
            else right--;
        }
    }

    cout << "IMPOSSIBLE" << endl;

}