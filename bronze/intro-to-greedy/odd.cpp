#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a&1) odd++;
        else even++;
    }

    while(odd > even){
        odd -=2;
        even++;
    }

    while(even > odd + 1){
        even = odd + 1;
    }

    cout << even + odd << endl;
    
}