#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int t = n%10;
        if(t == 0) n/=10;
        else n--;
    }
    cout << n;
}