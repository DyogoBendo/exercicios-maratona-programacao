#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
vector<int> castles[MAX+9];
int colors[MAX + 1];

vector<int> bfs(int n, int s){
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(s);
    
    while(!q.empty()){
        int current = q.front(); q.pop();
        visited[current] = true;
        for(auto neighbor : castles[current]){
            cout << neighbor << endl;
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
                parent[neighbor] = current;
                cout << parent[neighbor] << endl;
            } 
        }
    }
    return parent;
}

void paint(int s, int e, int c, vector<int> prev){
    int d = e; 
    while(d != s){
        colors[e] = c;
        d = prev[d];
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        castles[a].push_back(b);
        castles[b].push_back(a);
    }

    while(m--){
        int s, e, c;
        cin >> s >> e >> c;
        vector<int> parent = bfs(n, s);
        paint(s, e, c, parent);
    }

    for(int i = 1; i <= n; i++){
        cout << colors[i] << endl;
    }

    return 0;

}