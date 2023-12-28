#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int petals[n];
    for(int i = 0; i < n; i++) cin >> petals[i];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += petals[j];
            for(int k = i; k <= j; k++){
                if(sum == petals[k] * (j - i + 1)){
                    cnt++;
                    break;
                }
            }
        }
    }

    cout << cnt<< endl;
}