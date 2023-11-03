#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> a;
    vector<long long> b;
    if(n % 4 == 0){
        for(long long i = 1; i <= n; i++){
            if(i % 4 == 1 || i % 4 == 0) a.push_back(i);
            else b.push_back(i);
        }
    }else if(n % 4 == 3){
        for(long long i = 1; i <= n; i++){
            if(i % 4 == 1 || i % 4 == 2) a.push_back(i);
            else b.push_back(i);
        }
    }else{
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << a.size() << endl;
    for(auto v : a) cout << v << " ";
    cout << endl << b.size() << endl;
    for(auto v : b) cout << v << " ";
    cout << endl;

}