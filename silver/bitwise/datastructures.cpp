#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        vector<int> pfx(n+1, 0);
        int x0 = 0, x1 = 0;
        for(int i = 0; i < n; i++) cin >> arr[i];

        string s; 
        for(int i = 1; i <= n; i++){
            pfx[i] ^= arr[i-1] ^ pfx[i-1];
            char a; cin >> a;
            s+= a;
            if(a == '1') x1 ^= arr[i-1];
            else x0 ^= arr[i-1];
        }

        int q; cin >> q;
        while(q--){
            int a, b; cin >> a >> b;
            if(a == 2){
                cout << (b == 1 ? x1 : x0) << '\n';
            }else{
                int c; cin >> c;
                int x = pfx[c] ^ pfx[b-1];
                x1 ^= x;
                x0 ^= x;
            }
        }
    }
}