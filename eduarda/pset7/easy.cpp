#include <bits/stdc++.h>
using namespace std;

const int INF = 2147483647;

int main(){
    int test;
    cin >> test; 
    vector<string> answers;
    for(int t = 0; t < test; t++){
        int v, k;
        cin >> v >> k;
        queue<pair<int, int>> q; 
        vector<pair<int, int>> matrix[v];
        vector<int> visited(v, false);
        for(int j = 0; j < k; j++){
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            matrix[a].push_back(make_pair(b, c));
            matrix[b].push_back(make_pair(a, c));
        }

        int start, end;
        cin >> start >> end;
        start--;
        end--;

        int distance[v];
        for(int i = 0; i < v; i++){
            distance[i] = INF;
        }

        distance[start] = 0;
        q.push({start, 0});
        while(!q.empty()){
            int a = q.front().first; q.pop();
            if(visited[a]) continue;
            visited[a] = true;
            for(auto neighbor : matrix[a]){
                int b = neighbor.first; int w = neighbor.second;
                if(distance[a] + w < distance[b]){
                    distance[b] = distance[a] + w;
                    q.push({b, -distance[b]});
                }
            }
        }

        answers.push_back(distance[end] == INF ? "NO" : to_string(distance[end]));
    }

    for(int i = 0; i < test; i++){
        cout << answers[i] << endl;
    }
}