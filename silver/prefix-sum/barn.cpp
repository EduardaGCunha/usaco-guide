#include <bits/stdc++.h>
using namespace std;

const int MAXN = 202;
int grid[MAXN][MAXN], paint[MAXN][MAXN];

int main(){
    int n, k; cin >> n >> k;

    for(int i = 0; i < n; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        a++, b++, c++, d++;
        grid[a][b]++;
        grid[c][d]++;
        grid[a][d]--;
        grid[c][b]--;
    }

    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}