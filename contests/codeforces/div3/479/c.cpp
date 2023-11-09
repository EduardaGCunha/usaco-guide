#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int ans = k == 0 ? arr[0] - 1: arr[k-1];
    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] <= ans) cnt++;
    }

    if(k != cnt || !(1 <= ans)){
        cout << "-1" << endl;
        return 0;
    }

    cout << ans;
}