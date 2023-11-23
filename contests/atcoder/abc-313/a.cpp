#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    int a = p[0];
    sort(p.rbegin(), p.rend());
    
    if(a==p[0] && a!=p[1]){
        cout << 0 << endl;
        return 0;
    }
    cout << abs(a - p[0])+1 << endl;
}