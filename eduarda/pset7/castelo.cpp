#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

vector<int> g[MAX + 9];
int check[MAX + 9];
int maxD[MAX + 1];
int parent[MAX + 1];  // Store the parent of each node

void bfs(int n) {
    queue<pair<int, int>> q;
    q.push({n, 0});
    while (!q.empty()) {
        int root = q.front().first;
        int d = q.front().second;
        check[root] = true;
        for (int i = 0; i < g[root].size(); i++) {
            if (!check[g[root][i]]) {
                q.push({g[root][i], d + 1});
                parent[g[root][i]] = root;  // Store the parent of the child node
            }
        }
        maxD[root] = d;
        q.pop();
    }
}

vector<int> getShortestPath(int source, int destination) {
    vector<int> path;
    int current = destination;
    while (current != source) {
        path.push_back(current);
        current = parent[current];  // Move to the parent node
    }
    path.push_back(source);
    reverse(path.begin(), path.end());  // Reverse the path to get the correct order
    return path;
}

int main() {
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> v[n + 9];
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);
    int maxRoot = 0;
    for (int i = 1; i <= n; i++) {
        maxRoot = maxD[maxRoot] < maxD[i] ? i : maxRoot;
    }

    memset(maxD, 0, sizeof(maxD));
    memset(check, 0, sizeof(check));
    memset(parent, 0, sizeof(parent));

    bfs(maxRoot);
    maxRoot = 0;
    for (int i = 1; i <= n; i++) {
        maxRoot = max(maxRoot, maxD[i]);
    }

    cout << maxRoot << endl;

    // Find the shortest path between two nodes
    int source, destination;
    cout << "Enter the source and destination nodes: ";
    cin >> source >> destination;
    vector<int> shortestPath = getShortestPath(source, destination);
    cout << "Shortest Path: ";
    for (int node : shortestPath) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}