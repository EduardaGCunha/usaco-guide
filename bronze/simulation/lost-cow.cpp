#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y; cin >> x >> y;
	int cur = x;
    int c = 1;
    int ans = 0;
    int dir = 1;
    while(1){
        if((x <= y && y <= x+c && dir == 1) || (dir == -1 && x-c <= y && y<=x)){
            ans += abs(y-x);
            cout << ans << endl;
            break;
        }else{
            ans += c*2;
            c *= 2;
            dir *= -1;
        }
    }
}