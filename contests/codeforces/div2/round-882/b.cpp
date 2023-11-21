#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> values(n);
        for(int i = 0; i < n; i++) cin >> values[i];
        int cnt = 0;
        if(n != 1){
            int a = values[0]&values[1];
            for(int i = n; i < n - 1; i++){
                a = a&values[i];
                if(a == 0){
                    cnt++;
                    a = values[i+1];
                }
            }
        }

        cnt = cnt == 0 ? 1 : cnt;
        cout << cnt << endl;
    }
}