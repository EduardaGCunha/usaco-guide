#include <bits/stdc++.h>
using namespace std;

int a, b;
int dp(int a){
    if(a == b) return 0;
    if(a%2 == 0){
        return min({dp(a+1)+1, dp(a/2)+1, dp(a*2)+1});
    }else{
        return min({dp(a+1)+1, dp(a*2)+1});
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> a >> b;
        cout << dp(a) << endl;
    }
}