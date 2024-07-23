#include <bits/stdc++.h>
using namespace std;

const int MAXN  = 1e5;
int primo[MAXN+2];

int main(){
    primo[1] = 1;
    for(int i = 2; i < sqrt(MAXN); i++){
        for(int j = i; j < MAXN; j+=i){
            if(i == j) continue;
            primo[j] = 1;
        }
    }

    int n; cin >> n;
    if(primo[n]) cout << 'N' << endl;
    else cout << 'S' << endl;
}