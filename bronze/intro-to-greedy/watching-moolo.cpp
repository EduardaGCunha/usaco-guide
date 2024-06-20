#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n, k; cin >> n >> k;
    ll values[n];
    for(int i = 0; i < n; i++) cin >> values[i];
    ll cost = k + 1;
    for(int i = 1; i < n; i++){
        cost = min(cost + k + 1, cost + (values[i] - values[i-1]));
    }
    cout << cost << endl;
}