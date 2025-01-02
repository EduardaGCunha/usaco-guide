#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    cout << s.size() << endl;
    int cnt = 0;
    for(auto a : s){
        if(a=='"') cnt++;
    }
    cout << cnt << endl;
}