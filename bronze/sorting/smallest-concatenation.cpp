#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string val[n+1];
    for(int i = 0; i < n; i++) cin >> val[i];
    sort(val, val+n, [](const string &a, const string &b){return a+b < b+a;});
    for(int i = 0; i < n; i++) cout << val[i];
    cout << endl;

}