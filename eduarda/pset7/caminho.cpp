#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
vector<pair<int, int>> pontes[MAX +1];


int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int s, t, b;
        cin >> s >> t >> b;
        pontes[s].push_back(make_pair(t, b));
        pontes[t].push_back(make_pair(s, b));

    }
}