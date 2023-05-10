#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s, e;
    cin >> n; 
    vector<int> start;
    vector<int> end;
    for(int i = 0; i < n; i++){
        cin >> s >> e;
        start.push_back(s);
        end.push_back(e);
    } 


    int maxconsulta = 1;
    int consulta_atual = n-1;
    for(int i = n-2; i >= 0; i--){
        if(end[i] <= start[consulta_atual]){
            maxconsulta++;
            consulta_atual = i;
        }
    }
    cout << maxconsulta; 
}