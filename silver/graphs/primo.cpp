#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = n-1; i >= 2; i--){
        if(n%i){
            cnt++;
        }
    }

    if(cnt >= 1) cout << 'N';
    else cout << 'S' << endl;
}