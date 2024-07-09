#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MAXN = 1e3;
int arr[MAXN];

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i]; 
    }

    sort(arr, arr+n);

    int res = 0;
    for(int i = 0; i < n; i++){
        int  m = 0;
        int s = arr[i];
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(abs(arr[j]-s) <= k){
                m++;
                s = min(arr[j], s);
            }
        }
        res = max(res, m);
    }

    cout << res+1 << endl;
}