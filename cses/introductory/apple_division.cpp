#include <bits/stdc++.h>
using namespace std;

long long values[20];

int n;
long long dp(long long a, long long b, int i){
    if(i == n) return abs(b - a);
    return min(dp(a+values[i], b, i+1), dp(a, b+values[i], i+1));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }

    cout << dp(0, 0, 0) << endl;
}