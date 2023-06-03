#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> connections (112345);
bitset<112345> positions, visited;

int max_cats, result = 0;

void dfs(int vertex, int amount){
    visited[vertex] = true;
    if(positions[vertex] == 1){
        amount++;
        if(amount > max_cats) return;
    }else{
        amount = 0;
    }

    if(connections[vertex].size() == 1 && visited[connections[vertex][0]]) result++;
    else{
        for(auto neighbor : connections[vertex]){
            if(!visited[neighbor]){
                dfs(neighbor, amount);
            }
        }
    }
  
}

int main(){
    int n;
    cin >> n >> max_cats;
    vector<int> positions;
    vector<bool> visited(n, false);
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        positions.push_back(a);
    }

    for(int j = 0; j < n - 1; j++){
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    dfs(1, 0);
    cout << result;
}
