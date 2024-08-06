#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> arr(n+1, 0);
        for(int i = 0; i < m; i++){
            int l, r, val; cin >> l >> r >> val;
            arr[l] += val;
            arr[r+1] -= val;
        }

        for(int i = 1; i < n; i++){
            arr[i] += arr[i-1];
        }

        cin >> n;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            cout << arr[a] << endl;
        }
    }
}