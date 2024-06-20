#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("blocks.in", "r", stdin);
    int n; cin >> n;
    vector<int> alpha(26, 0);
    for(int i = 0; i < n; i++){
        vector<int> u(26, 0), v(26,0); string a, b; cin >> a >> b;
        for(int k = 0; k < a.size(); k++){
            u[a[k] - 'a']++;
        }
        for(int k = 0; k < b.size(); k++){
            v[b[k] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            alpha[i] += max(u[i], v[i]);
        }
       
    }
    
    freopen("blocks.out", "w", stdout);
    for(int i = 0; i < 26; i++){
        cout << alpha[i] << endl;
    }
}