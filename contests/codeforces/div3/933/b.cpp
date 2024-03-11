#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1];
        for(int i = 0; i < n; i++) cin >> arr[i];
        string res = "YES";
        bool br = 0;
        int sum = 0;
        while(br && sum > 0){
            sum = 0;
            for(int i = 0; i < n-1; i++){
                sum += arr[i];
                if(arr[i] >= arr[i-1] && arr[i] > arr[i+1]){
                    arr[i] -= 2;
                    arr[i+1]--;
                    arr[i-1]--;
                    if(arr[i-1] < 0 || arr[i+1] < 0 || arr[i] < 0){
                        res = "NO";
                        br = true;
                        break;
                    }
                }
            }
            sum += arr[n];
        }
        cout << res << endl;
    }
}