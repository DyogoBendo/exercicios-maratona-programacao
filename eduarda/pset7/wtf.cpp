#include <bits/stdc++.h>
using namespace std;

int matrix[8][8];
int dx[3]= {-1, 0, 1}, dy[3] = {-1, 0, 1};
string moves[3][3] = {{"LD", "L", "LU"}, {"D", "", "U"}, {"RD", "R", "RU"}};
vector<string> path[8][8];
queue<pair<int_fast64_t, int>> q;
char x1, x2;
int y1, y2;

int main(){
    cin >> x1 >> y1 >> x2 >> y2;
    //setting all of them as not visited;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            matrix[i][j] = -1;
        }
    }
    x1 = static_cast<int>(x1) - 97;
    x2 = static_cast<int>(x2) - 97;

    q.push(make_pair(x1 - 97, y1 - 1));
    matrix[x1][y1 - 1] = 0; //has been visited
    pair<int, int> front;
    while(!q.empty()){
        front = q.front();
        q.pop();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int nx = front.first + dx[i];
                int ny = front.second + dy[j];
                
                if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && matrix[front.first][front.second] == -1){
                    q.push({nx, ny});
                    matrix[nx][ny] = 0;
                    path[nx][ny] = path[front.first][front.second];
                    path[nx][ny].push_back(moves[i][j]);
                }
            }
        }
    }
    cout << matrix[x2][y2 - 1] << endl;
    for(string s : path[x2][y2 - 1]){
        cout << s << endl;
    }   

}