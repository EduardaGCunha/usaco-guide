#include <bits/stdc++.h>
using namespace std;

char mat[3][3];

int main(){
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    unordered_set<char> s1, s2, s3, s4;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> mat[i][j];
            s1.insert(mat[i][j]);
            s2.insert(mat[j][i]);
        }
        if(s1.size() <= 2) {
            s1.size() == 1 ? ans1++ : ans2++;
        }
        if(s2.size() == 2)  {
            s2.size() == 1 ? ans1++ : ans2++;
        }
    }
    int j = 2;
    for(int i = 0; i < 3; i++){
        s3.insert(mat[i][i]);
        s4.insert(mat[i][j]);
    }
    if(s3.size() == 2)  {
        s3.size() == 1 ? ans1++ : ans2++;
    }
    if(s4.size() == 2) {
        s4.size() == 1 ? ans1++ : ans2++;
    }

    cout << ans1 << endl;
    cout << ans2 << endl;

} 