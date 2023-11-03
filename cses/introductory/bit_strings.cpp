#include <bits/stdc++.h>
using namespace std;

long long M = 1000000007;

long long fastexpo(long long a, long long b){
    long long res = 1;
    while(b > 0){
        if(b%2) res = (res * a) % M;
        a = (a * a) % M;
        b /= 2;
    }
    return res;
}

int main(){
    long long n; cin >> n;
    cout << fastexpo(2, n) << endl;
}