#include <bits/stdc++.h>
using namespace std;

int main(){
    
    char v[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> v[i][j];
        }
    }

    int queens[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int ans = 0;

    do{
        set<int> diag1, diag2;
        for(int i = 0; i < 8; i++){
            if(v[i][queens[i]] == '*') break;
            diag1.insert(i + queens[i]);
            diag2.insert(i - queens[i]);
        }
        if(diag1.size() == 8 && diag2.size() == 8) ans++;
    }while(next_permutation(queens, queens + 8));

    cout << ans << endl;
}