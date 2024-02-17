#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, j = 0, ans = 0; cin >> n >> m >> k;
    int apartments[m+1], people[n+1];
    for(int i = 0; i < n; i++) cin >> people[i];
    for(int i = 0; i < m; i++) cin >> apartments[i];
    
    sort(apartments, apartments + m);
    sort(people, people + n);
    for(int i = 0; i < n; i++){
        while(j < m){
            if(apartments[j] + k < people[i]) j++;
            else if(apartments[j] - k > people[i]) break;
            else{
                j++;
                ans++; 
                break;
            }
        }
    }

    cout << ans << endl;
}