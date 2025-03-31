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
    map<string, int> ymp;
    for(int i = 0; i < 12; i++){
        ymp[years[i]] = i;
    }

    map<string, int> cymp;
    map<string, int> diff;
    cymp["Bessie"] = 0;
    diff["Bessie"] = 0;
    for(int i = 0; i < n; i++){
        string s, t, dir, a, p;
        cin >> p >> t >> t >> dir >> a >> t >> t >> s;
        int change = (dir == "previous" ? -1 : 1);
        int j = cymp[s];
        diff[p] = diff[s];
        cymp[p] = ymp[a];
        while(j != cymp[p]){
            j = (j + change)%12;
            diff[p]++;
            cout << j << endl;
        }
        cout << s << " " << cymp[s] << " " << diff[s] << endl;
        cout << p << " " << cymp[p] << " " << diff[p] << endl;
    }
    cout << diff["Elsie"] << endl;
}