#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int i = -12; i <= 12; i++){
        if(i == 0) continue;
        cout << i << " " << (12 - i)/(3*i) << endl;
    } 
}