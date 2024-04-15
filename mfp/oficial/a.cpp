#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, p; cin >> n >> p;
    int arr[n+1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int l = 1, r = (2e+14)+7;
    while(l < r){
        int mid = (l+r)/2;
        int i = 0, sum = 0;
        while(i < n){
            if(mid >= arr[i]){
                int a = mid/arr[i];
                sum += a;
            }
            i++;
            
        }
        if(sum < p){
            l = mid+1;
        }else{
            r = mid;
        }
    }  
    cout << l << endl;  
}