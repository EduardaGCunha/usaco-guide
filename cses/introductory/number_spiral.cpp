#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    while(n--){
        long long x, y;
        cin >> x >> y;
        long long t=0;
        if(x >= y){
            if(x%2 != 0) t = (x - 1)*(x- 1) + 1 + (y-1);
            else t = x*x - (y - 1);
        }else{
            if(y%2 == 0) t = (y - 1)*(y- 1) + 1 + (x-1);
            else t = y*y - (x - 1);
        }
        cout << t << endl;
    }

}
