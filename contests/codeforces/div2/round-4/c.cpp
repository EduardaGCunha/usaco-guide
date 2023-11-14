#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    map<string, int> val;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(val[s]){
            cout << s << val[s] << endl;
        }else{
            cout << "OK" << endl;
        }
        val[s]++;
    }
}