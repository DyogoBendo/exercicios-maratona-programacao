#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> idade;
    vector<vector<int>> conexao(n);
    vector<int> answers(n, 0);

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        idade.push_back({a, b});
        conexao[b].push_back(i);
    }
    stack<int> s;
    for(int i = 0; i < m; i++){
        int a, b, c;
        vector<bool> visited(n, false);
        cin >> a >> b >> c;
        a--; b--; c--;
        s.push(a); s.push(idade[a].second);
        visited[a] = true;
        visited[idade[a].second] = true;
        while(!s.empty()){
            int j = s.top(); s.pop();
            visited[j] = true;
            if(idade[j].first >= b && idade[j].first <= c){
                answers[j]++;
            }
            for(auto n : conexao[j]){
                if(!visited[n]){
                    s.push(n);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << answers[i] << " ";
    }
    cout << endl;
}
