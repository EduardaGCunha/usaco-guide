#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t; cin >> s;
    t = s;
    sort(s.begin(), s.end());
    if(s == t){
        cout << "Yes" << "\n";
        return 0;
    }
    cout << "No" << "\n";
}