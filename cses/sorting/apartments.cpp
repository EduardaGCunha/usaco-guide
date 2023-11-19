#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n, m, k, j = 0, cnt = 0; 
    cin >> n >> m >> k;
    vector<ll> clients(n), apartments(m);
    for(int i = 0; i < n; i++) cin >> clients[i];
    for(int j = 0; j < m; j++) cin >> apartments[j];

    for(int i = 0; i < n; i++){
        while(j < m){
            //if this is the case, i'd like to skip bcs the apartment size is less than desired
            if(apartments[j] + k < clients[i]) j++;

            //if this is the case, i know that all apartments from here are greater than my client's
            else if(apartments[j] - k > clients[i]) break;
            else{
                j++, cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;
}