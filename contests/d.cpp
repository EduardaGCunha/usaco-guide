#include <bits/stdc++.h>
using namespace std;


vector<int> graph[200005];

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
}