#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];

int farthestNode, maxDist;

void dfs(int u, int dist) {
    visited[u] = true;
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = u;
    }
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, dist + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // First DFS from an arbitrary node
    dfs(1, 0);
    // Second DFS from the farthest node
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(farthestNode, 0);
    cout << maxDist << endl;
    return 0;
}