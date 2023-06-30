#include <bits/stdc++.h>
using namespace std;


#define MAX 100000

vector<int> g[MAX+9];
int check[MAX+9];
int maxD[MAX+1];


/*
    To find the longest path using BFS, we can simply run it twice. 
    The first time, we run from the starting node 1.
    Our function will create a pair<int, int> queue that stores the current node and its distance from the root (which is our starting node). 
    While the queue is not empty, check if all neighbors from the current node are visited, and if not, add them to be visited. Each time you
    do that, you increase the distance from the starting point by 1. Each time that loop ends, you'll put that the distance from the starting 
    node to the ending node is equal to d. 

    When you do that again, but starting from the farthest node of the starting node, you'll find the farthest node from the farthest node. 
*/
void bfs(int n){
    queue<pair<int, int>> q;
    q.push({n, 0});
    while(!q.empty()){
        int root = q.front().first;
        int d = q.front().second;
        check[root] = true;
        for(int i = 0; i < g[root].size(); i++){
            if(!check[g[root][i]]){
                q.push({g[root][i], d + 1});
            }
        }
        maxD[root] = d;
        q.pop();
    }
}


int main(){
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> v[n+9];
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(1);
    int maxRoot = 0;
    for(int i = 1 ; i <= n; i++){
        maxRoot = maxD[maxRoot] < maxD[i] ? i : maxRoot;
    }
    
    memset(maxD, 0, sizeof(maxD));
    memset(check, 0, sizeof(check));
    bfs(maxRoot);
    maxRoot = 0;
    for(int i = 1; i <= n; i++){
        maxRoot = max(maxRoot, maxD[i]);
    }

    cout <<maxRoot<< endl;
    return 0;

}