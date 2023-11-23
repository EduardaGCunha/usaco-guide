#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n % 2 == 0){
            cout << n/2 << " " << n/2 << endl;
            continue;
        }

        if(n % 10 != 9){
            int a = (n+1)/2;
            int b = (n)/3;

            cout << a << " " << b << endl;
            continue;
        }

        for(int i = )
    }
}