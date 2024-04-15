#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    int time1= 0, time2 = 0;
    for(int i = 0; i < n; i++){
        string s, t; cin >> s;
        int a, b; 
        cin >> a >> b;
        if(a == 1){
            time1 += b;
        }else{
            time2 += b;
        }
    }
    cout << time1 << " x " << time2 << endl;
}