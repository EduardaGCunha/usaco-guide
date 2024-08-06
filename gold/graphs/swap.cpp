#include <bits/stdc++.h>
using namespace std;


unordered_set<string> visited;
queue<pair<string, int>> q;
int moves;
string cur;

void pswap(int x, int y){
    swap(cur[x], cur[y]);

    if(visited.find(cur) == visited.end()){
        q.push({cur, moves+1});
        visited.insert(cur);
    }
    //cout << cur << endl;
    swap(cur[x], cur[y]);
}

int main(){
    string s;

    int n = 3;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char a; cin >> a;
            s += a;
        }
    }

    //cout << s << endl;
    if(s == "123456789"){
        cout << 0 << endl;
        return 0;
    }

    visited.insert(s);
    q.push({s, 0});

    while(!q.empty()){
        tie(cur, moves) = q.front(); q.pop();
        //cout << c << endl;

        if(cur == "123456789"){
            cout << moves << endl;
            return 0;
        }

        for (int i = 0; i < 9; i += 3) {
			pswap(i, i + 1);
			pswap(i + 1, i + 2);
		}
		for (int i = 0; i < 3; i++) {
			pswap(i, i + 3);
			pswap(i + 3, i + 6);
		}
    }

}