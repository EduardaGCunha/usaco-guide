#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int fast_expo(long long b, long long p, long long m){
    long long result = 1;
    while(p > 0){
        if(p % 2 == 1){
            result = (result*b) % m;
        }
        b = (b * b) % m;
        p = p / 2;
    }

    return result;
}

int main(){
    long long n;
    cin >> n;

    long long r = fast_expo(8, n, 10);
    cout << r % 10 << endl;

}