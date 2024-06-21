#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int i = -1;
    int cnt = 0;
    while(i++ < n){
        if(a[i] == b[i]) continue;
        while(a[i] != b[i]) i++;
        cnt++;
    }
    cout << cnt << endl;
}