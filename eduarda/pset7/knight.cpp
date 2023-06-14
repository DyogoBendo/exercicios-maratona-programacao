#include <bits/stdc++.h>
using namespace std;


int dx[8] = {-1, 1, -2, 2, -1, 1, -2, 2};
int dy[8] = {2, 2, 1, 1, -2, -2, -1, -1};
queue<pair<int, int>> q; 
int matrix[8][8];

bool valid(pair<int, int> a, int mx, int my){
    int x = a.first + mx;
    int y = a.second + my;
    if (x >= 8 || x < 0) return false;
    if (y >= 8 || y < 0) return false;
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
        pair<int, int> aux, s;
        while(!q.empty()){
            aux = q.front(); q.pop();
            for(int i = 0; i < 8; i++){
                if (!valid(aux, dx[i], dy[i])) continue;
                s = {aux.first+dx[i], aux.second+dy[i]};
                if(matrix[s.first][s.second] == -1){
                    matrix[s.first][s.second] = matrix[aux.first][aux.second] + 1;
                    q.push(s);
                }
            }
        }
        answers.push_back(matrix[x2 - 'a'][y2 - 1]);
    }

    for(int i = 0; i < n; i++){
        cout << answers[i] << endl;
    }
    
}