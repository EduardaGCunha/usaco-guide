#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n;
int val[20];

ll solve(int y, ll sum1, ll sum2){
    if(y == n){
        //means we have found an arrangement
        return {abs(sum1 - sum2)};
    }
    return min(solve(y+1, val[y]+sum1, sum2), solve(y+1, sum1, val[y] + sum2));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> val[i];
    cout << solve(0, 0, 0) << endl;

}