#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt = 0;
        for(int i = 1; i*i <= n; i++){
            if(!(n%i)){
                cnt += (i*i == n? 1 : 2);
            }
        }
        cout << cnt << endl;
    }
}