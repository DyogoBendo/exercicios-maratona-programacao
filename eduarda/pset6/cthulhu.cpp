
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, parent;
    cin >> n >> m;
    vector<vector<int>> vertices(n);
    vector<bool> visited(n, false);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        vertices[a].push_back(b);
        vertices[b].push_back(a);
    }

    stack<int> stackers;
    //check if there is a cycle
    int total = 0;
    if(n != m){
        cout << "NO";
    }else{
        stackers.push(0);
        visited[0] = true;

        while(!stackers.empty()){
            int current = stackers.top();
            stackers.pop();
            total++;
            for(auto connections : vertices[current]){
                if(!visited[connections]){
                    stackers.push(connections);
                    visited[connections] = true;
                }
            }
        }

        if(total == n){
            cout << "FHTAGN!" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}