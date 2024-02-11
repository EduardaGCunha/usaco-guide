#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int t = 0, a = 0;
    while(n--){
        int x, y; cin >> x >> y;
        t+= x; a += y;
    }
    if(t > a){
        cout << "Takahashi" << endl;
    }else if (a > t){
        cout << "Aoki" << "\n";
    }else{
        cout << "Draw" << "\n";
    }
}