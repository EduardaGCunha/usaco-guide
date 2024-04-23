#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e5;
int n, k; 
int arr[MAXN];

bool check(double x){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += floor(arr[i]/x);
    }
    return cnt >= k;
}

signed main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    double l = 0, r = 1e8;
    for(int i = 0; i < 100; i++){
        double mid = (l + r)/2;
        if(check(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << setprecision(20) << l << endl;
}