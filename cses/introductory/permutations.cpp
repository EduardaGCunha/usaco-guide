#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    if(n == 2 || n == 3){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int a = 0;
    while(a+2 <= n){
        cout << a + 2 << " ";
        a += 2;
    }
    a = 1;
    while(a+2 <= n+2){
        cout << a << " ";
        a += 2;
    }

    cout << endl;
}