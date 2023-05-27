#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> rooms(n, vector<int>(m));
    point start, end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> rooms[i][j];
            if(rooms[i][j] == 2){
                start = {i, j};
            }else if(rooms[i][j] == 3){
                end = {i, j};
            }
        }
    }

    int path = 1;
    queue<point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            point current = q.front();
            q.pop();

            if(current.y == end.y && current.x == end.x){
                cout << path << endl;
                return 0;
            }

            for(int j = 0; j < 4; j++){
                int nx = current.x + dx[j];
                int ny = current.y + dy[j];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && rooms[nx][ny] != 0 && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    break;
                }
            }
        }
        path++;
    }
}