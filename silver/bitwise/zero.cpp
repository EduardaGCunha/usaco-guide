#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int sum = 0;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum ^= arr[i];
        }
        if(n&1) cout << sum << endl;
        else if(!sum) cout << sum << endl;
        else cout << -1 << endl;
    }
}