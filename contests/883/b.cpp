#include <bits/stdc++.h> 
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        vector<string> tictac(3);
        for(int i = 0; i < 3; i++){
            cin >> tictac[i];
        }

        string result = "DRAW";
        //checando por vencendor reto
        for(int i = 0; i < 3; i++){
            if(tictac[0][i] == tictac[1][i] && tictac[0][i] == tictac[2][i] && tictac[0][i] != '.'){
                result = tictac[0][i];
            }
            if(i == 0){
                if(tictac[0][i] == tictac[1][i+1] && tictac[0][i] == tictac[2][i+2] && tictac[0][i] != '.'){
                    result = tictac[0][i];
                }
            }
            if(i == 2){
                if(tictac[0][i] == tictac[1][i-1] && tictac[0][i] == tictac[2][i-2] && tictac[0][i] != '.'){
                    result = tictac[0][i];
                }
            }
        }

        for(int j = 0; j < 3; j++){
            int i = 0;
            if(tictac[j][i] == tictac[j][i+1] && tictac[j][i] == tictac[j][i+2] && tictac[j][i] != '.'){
                result = tictac[j][i];
            }
        }

        cout << result << endl;
    }
}