#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int gray = mask ^ (mask >> 1);
        cout << bitset<16>(gray).to_string().substr(16 - n) << '\n';
    }

    int a = 5, b = 3;
    cout << (a&b) << endl;
}