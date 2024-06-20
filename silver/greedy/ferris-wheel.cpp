#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    int arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int ans = 0;
    int i = 0, j = n - 1;
    while(i <= j){
        if(arr[i] + arr[j] > x){
            j--;
            ans++;
        }else if(arr[i] + arr[j] <= x){
            ans++;
            i++;
            j--;
        }
    }
    cout << ans << endl;
}