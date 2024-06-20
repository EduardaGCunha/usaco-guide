#include <bits/stdc++.h>
using namespace std;


//need to check which cows have exactly one entry point in between another's cow entry point
int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string s; cin >> s;
    vector<int> entry(26, -1);
    vector<int> exit(26, -1);
	for (int i = 0; i < s.size(); i++) {
		if (entry[s[i] - 'A'] == -1) {
			entry[s[i] - 'A'] = i;
		} else {
			exit[s[i] - 'A'] = i;
		}
	}

    int ans = 0;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            ans += (entry[i] < entry[j] && entry[j] < exit[i] && exit[i] < exit[j]);
        }
    }

    cout << ans << endl;
}