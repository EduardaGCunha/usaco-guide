#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int grid[MAXN][MAXN];

struct DSU {
    vector<int> parent, rank, size;

    DSU(int n) : parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }

    int componentSize(int x) {
        return size[find(x)];
    }
};

int main(){
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    int n; cin >> n;
    for(int i = 0; i < n;i ++){
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }

    vector<tuple<int, int, int, int, int>> edges;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i+1 < n){
                edges.push_back({abs(grid[i][j] - grid[i+1][j]), i, j, i+1, j});
            }if(j+1 < n){
                edges.push_back({abs(grid[i][j] - grid[i][j+1]), i, j, i, j+1});
            }
        }
    }

    DSU dsu(n*n);
    int target = ((n*n)+1)/2;
    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++){
        int c1 = get<1>(edges[i])*n + get<2>(edges[i]);
        int c2 = get<3>(edges[i])*n + get<4>(edges[i]);

        if(dsu.unite(c1, c2) && dsu.componentSize(c1) >= target){
            cout << get<0>(edges[i]) << endl;
            return 0;
        }
    }
}