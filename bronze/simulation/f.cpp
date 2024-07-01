#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

template<typename T> vector<int> manacher(const T& s){
    int l = 0, r = -1, n = s.size();
    vector<int> d1(n), d2(n);
    for(int i = 0; i < n; i++){
        int k = i > r ? 1 : min(d1[l+r-i], r-i);
        while(i+k < n && i-k >= 0 && s[i+k] == s[i-k]) k++;
        d1[i] = k--;
        if(i+k > r) l = i - k, r = i+k;
    }
    l = 0,r = -1;
    for(int i = 0; i < n; i++){
        int k = i > r ? 0 : min(d2[l+r-i+1], r-i+1); k++;
        while(i+k <= n && i-k >= 0 && s[i+k-1] == s[i-k]) k++;
        d2[i] = --k;
        if(i+k-1 > r) l = i - k, r = i+k-1;
    }

    vector<int> ret(2*n-1);
    for(int i = 0; i < n; i++) ret[2*i] = 2*d1[i]-1;
    for(int i = 0; i < n-1; i++) ret[2*i+1] = 2*d2[i+1];
    return ret;
}

template<typename T> struct palindrome {
    vector<int> man;
    palindrome(const T& s) : man(manacher(s)) {}
    bool query(int i, int j){
        return man[i+j] >= j-i+1;
    }
};

const int MAXN = 1e6;
vector<int> graph[MAXN];
int visited[MAXN];

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
}


signed main(){
    string s; cin >> s;
    palindrome p(s);
    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(p.query(i, j)){
                //cout << i << " " << j << endl;
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    for(int i = 0; i < n; i++) visited[i] = 0;
    int c = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            c++;
            dfs(i);
        }
    }

    cout << c << endl;

}