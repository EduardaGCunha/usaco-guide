#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        ll int n; cin >> n;
        cin>>t;
            while (t--){
                cin>>n;
                int a = 0,b = 0,bas = 1,cur = 0;
                while (n){
                    int x = n%10;
                    n/=10;
                    if (x%2 == 0) a+=bas*x/2,b+=bas*x/2;
                    else{
                        a+=bas*(x/2+cur),b+=bas*(x/2+1-cur);
                        cur^=1;
                    }
                    bas*=10;
                }
                cout<<a<<" "<<b<<"\n";
            }
}
}