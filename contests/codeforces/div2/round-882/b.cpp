#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> values(n);
        for(int i = 0; i < n; i++) cin >> values[i];
        int a = values[0], cnt = 1;
        for(int i = 0; i < n; i++){
            a &= values[i];
            if(a == 0){
                if(i==n-1) break;
                cnt++;
                a = values[i+1];
            }
        }
        if(a != 0) cnt--;
        cnt = max(cnt, 1);
        cout << cnt << endl;
    }
}