#include <bits/stdc++.h>
using namespace std;

vector<string> years = {
    "Ox",
    "Tiger",
    "Rabbit", 
    "Dragon",
    "Snake", 
    "Horse",
    "Goat",
    "Monkey",
    "Rooster",
    "Dog",
    "Pig",
    "Rat"
};

int main(){
    int n; cin >> n;
    map<string, int> ymap;
    for(int i = 1; i <= 12; i++){
        ymap[years[i]] = i;
    }
    map<string, string> cowy;
    int ans = 0;
    cowy["Bessie"] = "Ox";
    for(int i = 0; i < n; i++){
        string s, l, y, t, f;
        cin >> s >> l >> l >> f >> y >> l >> l >> t;
        if(f == "previous"){
            //vou pegar o ano q nasceu
            int a = 12 - (ymap[y] - ymap[cowy[t]]);
            cowy[s] = a;
        }else{
            int a = 
        }
    }
}