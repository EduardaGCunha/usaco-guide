#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
    vector<string> permutations;
    cin >> s;
    sort(s.begin(), s.end());

    do{
        permutations.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout << permutations.size() << endl;

    for(auto a : permutations) cout << a << endl;
}