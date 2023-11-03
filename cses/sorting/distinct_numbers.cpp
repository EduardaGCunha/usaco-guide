#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    set<int> values;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        values.insert(a);
    }

    cout << values.size() << endl;
}