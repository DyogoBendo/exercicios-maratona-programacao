#include <bits/stdc++.h>
using namespace std;


void bfs(vector<vector<int>> &graph, int start, int n, int end, vector<int> &colors, int color){
    queue<int> q;
    vector<bool> visited(n);
    vector<int> parent(n);
    q.push(start);
    int current;
    visited[start] = true;
    parent[start] = -1;

    while(!q.empty()){
        current = q.front(); q.pop();

        if(current == end){
            break;
        }
    
        for(auto neighbor : graph[current]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    while(current != -1){
        colors[current] = color;
        current = parent[current];
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> colors(n);
    for (int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        s--;
        e--;
        bfs(v, s, n, e, colors, c);
    }

    for (int p : colors)
    {
        cout << p << " ";
    }
    cout << endl;


    return 0;
}