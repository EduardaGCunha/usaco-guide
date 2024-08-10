#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+1;
pair<int, int> coord[MAXN];
int p[MAXN], r[MAXN], sum[MAXN];



int get(int a){
    return p[a] = (p[a] == a)? a : get(p[a]);
}

bool unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return false;
    if(r[a] == r[b]) r[a]++;
    if(r[a] > r[b]) {
        p[b] = a;
        sum[a] += sum[b];
    }
    else{
        p[b] = a;
        sum[b] += sum[a];
    }
    return true;
}


int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        sum[i] = 1;
        r[i] = 0;
        p[i] = i;
        cin >> coord[i].first >> coord[i].second;
    }

    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int x = abs(coord[i].first - coord[j].first);
            int y = abs(coord[i].second - coord[j].second);

            edges.push_back({x*x + y*y, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    int last = 0;
    int c = 0;

    for(int i = 0; i < edges.size(); i++){
        int dist = get<0>(edges[i]);
        int x = get<1>(edges[i]);
        int y = get<2>(edges[i]);
        if(unite(x, y)){
            c++;
            last = dist;
        }
        if(c == n-1) break;
    }

    cout << last << endl;

}