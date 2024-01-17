#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k; cin >> n >> k;
    unordered_map<long long,long long> prefix;
    long long ans = 0;
    for(long long i = 0, sum = 0; i < n; i++){
        long long a; cin >> a;
        prefix[sum]++;
        sum += a;
        ans += prefix[(sum - k)];
    }
    cout << ans << endl;
}