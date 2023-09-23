#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> apples;
        for(int i = 0; i < n; i++){
            cin >> apples[i];
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(apples[i] == -1) continue;
            ans = k - i;
            for(int j = 0; j < n; j++){
              
            }
        }

        cout << ans;
    }
}