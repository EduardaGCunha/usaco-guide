#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
bool arr[MAXN + 1];
int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        arr[a] = true;
    }

    vector<int> b, e;
    for(int i = 1; i <= 2*n; i++){
        if(arr[i]==1) e.push_back(i);
        else b.push_back(i);
    }

    int i = 0, j = 0, ans = 0;
    while(i < n && j < n){
        if(b[i] > e[j]){
            ans++; i++; j++;
        }else{
            i++;
        }
    }

    cout << ans << endl;
}