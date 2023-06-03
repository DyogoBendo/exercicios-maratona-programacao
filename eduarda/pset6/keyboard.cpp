#include <bits/stdc++.h>
using namespace std;

bool hasCycle(vector<set<int>>& grafo);
bool dfs(vector<set<int>>& grafo, int start, vector<bool> visited, vector<int>& stackers);

int main(){
    int n;
    cin >> n;

    //adding values
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        int x = input.size();
        int start = 0;
        int end = 1;
        vector<set<int>> vertices(26);
        while(x--){
            int a = static_cast<int>(input[start]) - 97;
            int b = static_cast<int>(input[end]) - 97;
            if(end == input.size()){
                break;
            }else{
                vertices[a].insert(b);
                vertices[b].insert(a);
            }
            start++, end++;
        }
        bool result = hasCycle(vertices);
        vertices.clear();
        
    }

}


//check if there is a cycle
bool dfs(vector<set<int>>& grafo, int start, int parent, vector<bool> visited){
    visited[start] = true;

    for(auto neighbor : grafo[start]){
        if(!visited[neighbor]){
            if(dfs(grafo, neighbor, start, visited)){
                return true;
            }
        }
        else if(neighbor != parent){
            return true;
        }
    }

    return false;
}

bool hasCycle(vector<set<int>>& grafo){
    int n = grafo.size();
    vector<bool> visited(n, false);
    vector<bool> stackers(n, false);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfs(grafo, i, -1, visited)) return true;
        }
    }

    return false;
}