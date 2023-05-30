#include <bits/stdc++.h>
using namespace std;

vector<int> ar[10001];
int visited[10001];

int max_distance, max_node;

int dfs(int node, int d){
    visited[node] = 1;
    if(d > max_distance){
        max_distance = d;
        max_node = node;
    }

    for(int child : ar[node]){
        if(visited[child] == 0){
            dfs(child, d+1);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    max_distance = -1;
    dfs(1, 0);

    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    max_distance = -1;
    dfs(max_node, 0);

    cout << max_distance;
}