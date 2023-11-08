#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int result = 3;
    for(int i = 2; i < n; i++){
        result = (result * 2) + 1;
    }
    cout << result << endl;
}