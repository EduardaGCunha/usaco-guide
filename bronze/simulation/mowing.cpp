#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
int grid[MAXN][MAXN];

int main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int n; cin >> n;
    int t = 1, x = 2500, y = 2500;
    int ans = INT_MAX;
    while(n--){
        char a; int b; cin >> a >> b;
        if(a == 'N'){
            while(b--){
                if(grid[x][y]){
                    ans = min(abs(grid[x][y] - t), ans);
                }
                grid[x][y] = t;
                x++;
                t++;
            }
        }else if(a == 'E'){
            while(b--){
                if(grid[x][y]){
                    ans = min(abs(grid[x][y] - t), ans);
                }
                grid[x][y] = t;
                y++;
                t++;
            }
        }else if(a == 'S'){
            while(b--){
                if(grid[x][y]){
                    ans = min(abs(grid[x][y] - t), ans);
                }
                grid[x][y] = t;
                x--;
                t++;
            }
        }else{
            while(b--){
                if(grid[x][y]){
                    ans = min(abs(grid[x][y] - t), ans);
                }
                grid[x][y] = t;
                y--;
                t++;
            }
        }
    }
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

}