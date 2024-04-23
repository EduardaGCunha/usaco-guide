#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;
int n, m, c;
int arr[MAXN];

bool check(int x){
    int cnt = 1; 
    int first = arr[0];
    int cp = 0;
    for(int i = 0; i < n; i++){
        cp++;
        if(arr[i] - first > x || cp > c){
            cnt++;
            cp = 1;
            if(cnt > m) return false;
            first = arr[i];
        }
    }   
    return true;
}
signed main(){
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int l = 0, r = 1e18;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout << r << endl;
}