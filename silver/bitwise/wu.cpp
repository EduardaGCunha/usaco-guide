#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

/*
guardo todos os numeros em um contador
vao ter no maximo 4096 numeros distintos
posso brutar todas as bitmaks i, j 
guardar a resposta p/ bitmask i pq em algum momento eu volto pra bitmask j
a resposta seria os wu value pra cada soma possivel de 0 a 100
*/

const int MAXN = 4097;
const int MAXM = 103;
int ans[MAXN][MAXM], qtd[MAXN];

int stoi2(string s){
    int num = 0;
    for(int i = 0; i < s.size(); i++){
        num = (num << 1) + (s[i] - '0');
    }
    //cout << num << endl;
    return num;
}


int main(){
    fastio;
    int n, m, q; cin >> n >> m >> q;

    int wu[n];
    for(int i = 0; i < n; i++) cin >> wu[i];
    
    
    for(int i = 0; i < m; i++){
        string s; cin >> s;
        int x = stoi2(s);
        qtd[x]++;
    }
    //cout << "passou dos numeros\n";

    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < (1<<n); j++){
            //inverso do xor: (i^j) me retorna todas as posicoes diferentes
            //se eu fizer xor disso com (1<<n-1), vou ter todas as posicoes iguais
            int x = (i^j)^((1<<n)-1), sum = 0;
            for(int k = 0; k < n && sum <= 100; k++){
                //pegando o kesimo bit se estiverem iguais
                if(x&(1<<k)) sum += wu[n-k-1];
            }
            //resposta p/ query i com essa soma eh a qtd q a bitmask j apareceu
            if(sum <= 100) ans[i][sum] += qtd[j];
        }

        for(int j = 1; j <= 100; j++){
            ans[i][j] += ans[i][j-1];
        }
    }

    while(q--){
        string s;
        int w; cin >> s >> w;
        int x = stoi2(s);
        cout << ans[x][w] << endl;
    }
}