#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n; cin >> n;
    int arr[n];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ans += arr[i];
    }

    ans = -ans;
    for(int i = 0; i < 30; i++){
        int sum = 0;
        int pfx[]= {1, 0};
        for(auto a : arr){
            sum ^= (a>>i)&1; 

            ans += pfx[sum ^1] * 1LL << i;
            pfx[sum]++;
        }
    }

    cout << ans << endl;
}