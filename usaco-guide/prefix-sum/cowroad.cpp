#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, b; cin >> n >> k >> b;
    vector<int> arr(n, 0);
    for(int i = 0; i < b; i++){
        int a; cin >> a;
        arr[a] = 1;
    }

    vector<int> prefix(n, 0);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix[i] += prefix[i-1];
    }
}