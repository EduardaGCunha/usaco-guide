#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n;
    long long current = 5, ans = 0;
    while(current <= n){
        ans += n / current;
        current *= 5;
    }
    cout << ans << endl;

}