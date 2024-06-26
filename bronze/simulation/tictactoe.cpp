#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    freopen("tttt.in", "r",stdin);
    freopen("tttt.out", "w",stdout);
    char arr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    set<set<char>> ans1;
    set<set<char>> ans2;
    //searching horizontal
    for(int i=0;i<3;i++){
        set<char> s;
        for(int j=0;j<3;j++){
            s.insert(arr[i][j]);
        }
        if(s.size()==1) ans1.insert(s);
        if(s.size()==2) ans2.insert(s);
    }
    //searching vertical
    for(int j=0;j<3;j++){
        set<char> s;
        for(int i=0;i<3;i++){
            s.insert(arr[i][j]);
        }
        if(s.size()==1) ans1.insert(s);
        if(s.size()==2) ans2.insert(s);
    }
    //searching diagonal
    set<char> s;
    s.insert(arr[0][0]);
    s.insert(arr[1][1]);
    s.insert(arr[2][2]);
    if(s.size()==1) ans1.insert(s);
    if(s.size()==2) ans2.insert(s);
    set<char> s1;
    s1.insert(arr[0][2]);
    s1.insert(arr[1][1]);
    s1.insert(arr[2][0]);
    if(s.size()==1) ans1.insert(s);
    if(s.size()==2) ans2.insert(s);
    cout<<ans1.size()<<endl<<ans2.size();
}