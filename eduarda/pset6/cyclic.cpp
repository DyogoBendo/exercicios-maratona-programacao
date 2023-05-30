#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000 + 11;

int deg[N];
bool visited[N];
vector<int> vertices[N];
vector<int> comp;

void dfs(int value){
    visited[value] = true;
    comp.push_back(value);
    for(auto neighbor : vertices[value]){
        if(!visited[neighbor]) dfs(neighbor);
    }

}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        vertices[a].push_back(b);
        vertices[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    int answer = 0;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            comp.clear();
            dfs(i);
            bool test = true;
            for(auto var : comp){
                if(deg[var] != 2)
                    test = false;
            }
            if(test){
                answer++;
            }
        }
    }

    cout << answer;
}