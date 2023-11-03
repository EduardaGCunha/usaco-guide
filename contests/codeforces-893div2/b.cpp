#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;

        int cnt = 0x3f3f3f3f;
        int even_cnt = 0;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            int b = a % k == 0 ? 0 : k - (a % k);
            a % 2 == 0? even_cnt++ : even_cnt;
            cnt = min(cnt, b);
        }

        if(k == 4){
            cnt = max(0, 2 - even_cnt);
        }
        cout << cnt << endl;
        

    }
}