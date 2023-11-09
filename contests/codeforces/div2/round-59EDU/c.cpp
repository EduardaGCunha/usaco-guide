#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k; cin >> n >> k;
    vector<int> values(n);
    for(auto v : values) cin >> values[v];
    string s; cin >> s;

    int i = 0;
    int j = 0;
    int sum = 0;
    while(i < n){
        if(s[i] != s[i+1]){
            sum+= values[i];
            continue;
        }
        j = i +1;
        while(s[i] == s[j++]){
            sum += max(values[i], values[j]);
            k--;
            i+=2, j+=2;
        }

    }

    cout << sum << endl;
}