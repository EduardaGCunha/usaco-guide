#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b; cin >> a >> b;
    int c = a|b;
    int d = a&b;
    cout << "xor: " << c << endl;
    cout << "and: " << d << endl;
}