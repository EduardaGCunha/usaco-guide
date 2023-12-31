#include <bits/stdc++.h>
using namespace std;

set<string> permutations;
string s;
int n;
bool vis[10];

void search(int curr, string str){
    if(curr == n){
        permutations.insert(str);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = true;
            search(curr+1, str+s[i]);
            vis[i] = false;
        }
    }
}

int main(){
    cin >> s;
    n = s.size();
    memset(vis, false, n);
    search(0, "");
    for(auto a : permutations) cout << a << endl;
}  