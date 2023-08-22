#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, s, r;
    cin >> n >> s >> r;
    vector<int> ans;
    ans.push_back(s - r);
    int sum = 0;
    for(int i = 1; i <= n - 1; i++){
        ans.push_back(1);
        sum++;
    }
    int add = r - sum;
    for(int i = 1; i < n; i++){
        if(add <= 0) break;
        int mn = min(s - r - 1, add);
        ans[i] += mn;
        add -= mn;
    }  
    
    for(int x : ans) cout << x << " ";
    cout << endl; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    }
}