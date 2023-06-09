#include <bits/stdc++.h>
using namespace std;


int dx[8] = {-1, 1, -2, 2, -1, 1, -2, 2};
int dy[8] = {2, 2, 1, 1, -2, -2, -1, -1};
queue<pair<int, int>> q; 
int matrix[8][8];

bool valid(int nx, int ny){
    if(!nx && !ny) return false;

    if(nx >= 8 || nx < 0) return false;
    if(ny >= 8 || ny < 0) return false;
    return true;
}

int main(){
    int t;
    cin >> t;
    int n = t;
    vector<int> answers;
    char x1, x2;
    int y1, y2;
    while(t--){
        for(int i = 0; i <8; i++){
            for(int j = 0; j < 8; j++){
                matrix[i][j] = -1;
            }
        }
        cin >> x1 >> y1 >> x2 >> y2;

        q.push(make_pair(x1 - 'a', y1 - 1));
        matrix[x1 - 'a'][y1 - 1] = 0;
        pair<int, int> aux;
        while(!q.empty()){
            aux = q.front(); q.pop();
            for(int i = 0; i < 8; i++){
                int nx = aux.first + dx[i];
                int ny = aux.second + dy[i];
                if(valid(nx, ny) && matrix[nx][ny] == -1){
                    matrix[nx][ny] = matrix[aux.first][aux.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
        answers.push_back(matrix[x2 - 'a'][y2 - 1]);
    }

    for(int i = 0; i < n; i++){
        cout << answers[i] << endl;
    }
    
}