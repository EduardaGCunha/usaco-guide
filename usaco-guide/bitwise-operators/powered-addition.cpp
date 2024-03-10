#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a = INT_MIN;
        vector<int> v;
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            int b; cin >> b;
            if(b > a) v.push_back(a);
            mx = max(mx, a);  
        }

        int t = 1;
        while(1){
            
        }
    }
}