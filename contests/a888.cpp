#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    set<string> cnt;
    for(int i = 1; i < n; i++){
        cnt.insert(string(1, str[i - 1]) + string(1, str[i]));
    }
    
    cout << cnt.size() << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}