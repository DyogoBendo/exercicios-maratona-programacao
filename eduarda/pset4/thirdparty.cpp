#include <bits/stdc++.h>
using namespace std;

vector<int> starts;
vector<lib> libs;
struct lib{
    int end, index;
    bool operator<(const lib &l){
        if (end != l.end) return end > l.end;
        return index < l.index;
    }
};

int main(){
    int n, m; cin >> n >> m;
    int x, y;
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        starts.push_back(x);
        libs.push_back(lib{y, i});
    }
    sort(libs.begin(), libs.end());
    int current=n;
     
}