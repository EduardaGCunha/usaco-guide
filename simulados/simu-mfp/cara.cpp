#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) && n!= 0){
        int m = 0, j = 0;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            if(a == 0) m++;
            else j++;
        }
        cout << "Mary won " << m << " times and John won " << j << " times" << endl; 
    }
}