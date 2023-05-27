#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vertices(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        vertices[a].push_back(b);
        vertices[b].push_back(a);
    }  

    vector<bool> visited(n, false);
    int groups = 0;
    stack<int> stackers;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            groups += 1;
            visited[i] = true;
            stackers.push(i);
            while(!stackers.empty()){
                int a = stackers.top();
                visited[a] = true;
                stackers.pop();
                vector<int> friends = vertices[a];
                for(auto fr : friends){
                    if(!visited[fr]){
                        stackers.push(fr);
                    }
                }
            }
        }
    }

    cout<< groups;
}
