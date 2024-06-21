#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string a; cin >> a;
        string b = a;
        sort(a.rbegin(), a.rend());
        if(a == b){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
            cout << a << endl;
        }
    }
}