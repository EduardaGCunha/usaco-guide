#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t; cin >> t;
    while(t--){
        long long k, x; cin >> k >> x;
        long long res =(k-1)*9 + x;
        cout << res << endl;
    }
}