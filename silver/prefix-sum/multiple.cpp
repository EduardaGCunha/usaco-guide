#include <bits/stdc++.h>
using namespace std;

/*
imagine q minha string eh 
1234
e quero saber quantas substrings sao divisiveis por 3
ao inves de passar por toda substring possivel, posso usar a ideia de sufixo
p/ cada sufixo, eu descubro 1234 - 4 = 1230 e isso eh divisivel por 3 
se sufixo1 % M = sufixo2 % M, significa que sufixo1%M - sufixo2%M = 0 mod M
assim eu descubro p todo sufixo
eu posso me basear em todos os mods de sufixo pra calcular minha resposta
*/

#define int long long
const int MOD = 2019;
signed main(){
    string s; cin >> s;
    int ans = 0, exp = 1, suf = 0;
    int n = s.size();
    vector<int> mods(MOD);
    mods[0]++;
    for(int i = n-1; i >= 0; i--){
        int digit = s[i] - '0';
        suf = (suf + digit*exp)%MOD;
        exp = (exp*10)%MOD;
        ans += mods[suf];
        mods[suf]++;
    }

    cout << ans << endl;
}