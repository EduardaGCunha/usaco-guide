#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n; cin >> n;
    vector<int> val(7, -1);
    int s = 0, ans = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        s = (s+a)%7;
        if(val[s] == -1){
            val[s] = i;
        }else{
            ans = max(ans, i - val[s]);
        }
    }
    
    cout << ans << endl;
}