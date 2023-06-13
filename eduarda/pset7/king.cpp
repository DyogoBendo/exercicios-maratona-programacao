#include <bits/stdc++.h>
using namespace std;

bool valid(pair<int, int> a, int mx, int my){
    if (!mx && !my) return false;
    int x = a.first + mx;
    int y = a.second + my;
    if (x >= 8 || x < 0) return false;
    if (y >= 8 || y < 0) return false;
    return true;
}

int main(){
    int dist[8][8];
    vector<string> path[8][8];
    char x1, x2;
    int y1, y2;

    queue< pair<int, int> > q;
    int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};
    string moves[3][3] = {{"LD", "L", "LU"}, {"D", "", "U"}, {"RD", "R", "RU"}};
    
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            dist[i][j] = -1;
        }
    }

    q.push(make_pair(x1 - 'a', y1 - 1));
    dist[x1 - 'a'][y1 - 1] = 0;
    pair<int, int> s, aux;
    while(!q.empty()){
        aux = q.front(); q.pop();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int nx = aux.first + dx[i];
                int ny = aux.second + dy[j];
                if(valid(aux, dx[i], dy[j]) && (dist[nx][ny] == -1)){
                    s = {nx, ny};
                    dist[nx][ny] = dist[aux.first][aux.second] + 1;
                    path[nx][ny] = path[aux.first][aux.second];
                    path[nx][ny].push_back(moves[i][j]);
                    q.push(s);
                }
            }
        }
    }
    cout << dist[x2-'a'][y2-1] << endl;
    for (string a: path[x2-'a'][y2-1]){
        cout << a << endl;
    }
}

