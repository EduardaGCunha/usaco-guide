#include <bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n%2 == 0){
            cout << "No" << endl;
            continue;
        }

        cout << "Yes" << endl;
        int j = 2*n;
        for(int i = 1; i < j && i <=n; i+=2, j--){
            cout<<i<<' '<<j<<endl;
        }

        for(int i = 2; i < j; i+=2, j--){
            cout << i << " " << j << endl;
        }
    }
}