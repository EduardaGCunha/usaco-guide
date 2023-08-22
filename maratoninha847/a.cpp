#include <bits/stdc++.h>
using namespace std;

string pi = "314159265358979323846264338327";

int main(){
    int t;
    cin >> t;
    while(t--){
        int cnt = 0;
        string a;
        cin >> a;
        for(int i = 0; i < 30; i++){
            if(a[i] != pi[i]) break;
            cnt++;
        }
        cout << cnt << endl;
    }
}