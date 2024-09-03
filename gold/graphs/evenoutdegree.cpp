#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> adj[100001];  // adjacency list for the graph
vector<pair<int, int>> result;  // to store the final directed edges
bool visited[100001];
int parent[100001];

void dfs(int node) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            dfs(neighbor);
        }
    }

    // Now backtrack and set directions
    for (int neighbor : adj[node]) {
        if (neighbor != parent[node]) {
            if (!visited[neighbor] || parent[node] == neighbor) {
                // Direct edge from current node to neighbor
                result.push_back({node, neighbor});
            } else {
                // Reverse edge direction if it's a back edge or already visited node
                result.push_back({neighbor, node});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    // Check if we used all edges
    if (result.size() != m) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Output the result
    for (auto edge : result) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}
