#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1007;
int arr[MAXN];

int main(){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        arr[a] = c;
        arr[b] = -c;
    }

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < 1000; i++){
        cnt += arr[i];
        ans = max(cnt, ans);
    }

    cout << ans << endl;
}