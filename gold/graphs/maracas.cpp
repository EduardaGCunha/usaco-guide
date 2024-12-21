#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7; 

vector<pair<int,pair<int,int>>> pares;
vector<int> impares;
vector<int> visited (MAXL, 0);

signed main() {_
    int n;
    cin >> n;
    int nimpars = 0;
   
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a %2 != 0) {
            impares.push_back(i);
            nimpars++;
        }
    }
    int a, b;
    cin >> a >> b;
    int menor = min(a,b);
    if (nimpars %2 != 0) {
        cout << "-1" << endl;
        return 0;
    }
    
    for (int i = 0 ; i < impares.size()-1; i++){
        int dist = abs(impares[i] - impares[i+1]);
        pares.push_back({dist,{impares[i], impares[i+1]}});
    }
    pares.push_back({abs(n-impares[impares.size()-1] + impares[0]),{impares[0],impares[impares.size()-1]}});
    
    sort(pares.begin(), pares.end(), greater<pair<int,pair<int,int>>>());
    int ans = 0;
    for (auto u : pares){
        int d = u.first;
        int p = u.second.first;
        int s = u.second.second;
        if (visited[p] < 2 || visited[s] < 2){
            visited[p]++;
            visited[s]++;
        }
        //cout << d << " " << p << " " << s << endl;
        if (visited[p] == 2 ){
            ans+=d;
            visited[s] = 3;
             //cout << "n adicionado " << p << endl;
            continue;
        }
        else if (visited[s] == 2){
            ans+=d;
            visited[p] = 3;
            //cout << "n adicionado " << s << endl;
            continue;
        }
        
       // cout << visited[p] << " " << visited[s] << endl;
        
        
    }
    cout << ans*menor << endl;
}