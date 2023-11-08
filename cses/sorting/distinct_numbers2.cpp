#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> val(n);
    for(int i = 0; i < n; i++) cin >> val[i];
    sort(val.begin(), val.end());

    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(val[i] != val[i+1]) ans++;
    } 

    cout << ans + 1 << endl;
}