#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> prefixH(n+1, 0), prefixS(n+1, 0), prefixP(n+1, 0);
    for(int i = 0; i < n; i++){
        char a; cin >> a;
        if(a=='H') prefixS[i+1] = prefixS[i] + 1;
        else if(a=='S') prefixH[i+1] = prefixH[i] + 1;
        else prefixP[i+1] = prefixP[i]+1;
    }

    for(int i = 0; i <= n; i++){
        cout << prefixP[i] << endl;
    }

}