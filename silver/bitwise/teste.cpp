#include <bits/stdc++.h>
using namespace std;

int main(){
    int a; cin >> a;
    cout << (a&(a-1)) << endl;
    if((a&(a-1)) == 0){
        cout << "sim" << endl;
        int b = __builtin_ctz(a);
        cout << b << endl;
    }
}