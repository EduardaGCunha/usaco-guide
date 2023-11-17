#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a = (n-1) * n;
        int sum = 0;
        for(int i = 1; i < n - 1; i++){
            sum += i*i;
        }
        sum += a;
        cout << sum << endl;
    }
}