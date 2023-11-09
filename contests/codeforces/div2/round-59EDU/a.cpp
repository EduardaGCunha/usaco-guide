#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s, x, y;
        cin >> s;
        for(int i = 0; i < 1; i++){
            x += s[i];
        }
        for(int i = 1; i < n; i++){
            y += s[i];
        }

        if(x[0] >= y[0] && y.length() == 1){
            cout<<"NO\n";
        }else{
            cout<<"YES"<<endl<<2<<endl;
            cout<<x[0]<<" ";
            for(int i=0; i<y.length(); i++){
                cout<<y[i];
            }cout<<endl;
        }
    }
    return 0;
}