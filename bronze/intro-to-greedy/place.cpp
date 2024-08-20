#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> sorted(arr);
    sort(arr.begin(), arr.end());
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != sorted[i]){
            cnt++;
        }
    }

    cout << cnt - 1 << endl;
}