#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, x1, y1, x2, y2; 
        cin >> n >> x1 >> y1 >> x2 >> y2;
        int a = min({x1, y1, n + 1 - x1, n + 1 - y1});
        int b = min({x2, y2, n + 1 - x2, n + 1 - y2});
        cout << abs(a-b) << endl;
    }
}