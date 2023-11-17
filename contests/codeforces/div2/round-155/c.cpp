#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        s.push_back('#');
        int cnt = 1;
        long long int x = 0, t = 1;
        int mod = 998244353;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) cnt++;
            else{
                x+=(cnt-1);
                t=(t*cnt)%mod;
                cnt=1;
            }
        }

	    for(int i=2;i<=x;i++) t=(t*i)%mod;
		cout<<x<<" "<<t<<"\n";
    }
}