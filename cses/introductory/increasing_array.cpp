#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    long long prev = 0; long long cnt = 0;
    for(int i = 0; i < n; i++){
        long long a; cin >> a;
        if(a < prev){
            cnt += prev - a;
            a+= prev - a;
        }
        prev = a;
    }
    cout << cnt << endl;
}