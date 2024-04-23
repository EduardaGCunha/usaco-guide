#include <bits/stdc++.h>
using namespace std;

#define int long long
int w, h, n;

bool check(int x){
    int a = x/w;
    int b = x/h;
    //cout << (a*b) << " " << (a*b >= n) << endl;
    return (x/w)*(x/h) >= n;
}
signed main(){
    cin >> w >> h >> n;
    int l = 0, r = 1;
    while(!check(r)) r *=2;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << endl;
}