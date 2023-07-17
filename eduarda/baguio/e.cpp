#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define int ll
const int INF = 0x3f3f3f3f3f3f3f3f;
void solve(){
    int n; cin >> n;
    vector<int> p(n),e(n);
    for(auto &x:p) cin >> x;
    for(auto &x:e) cin >> x;
    sort(all(p));
    map<int,int> m;
    for(auto x:e) m[x]++;
    set<int> pos_ans;
    for(auto x:e) pos_ans.insert(p[0]+x),pos_ans.insert(p[0]-x);
    for(auto x:pos_ans){
        map<int,int> mm;
        bool can = true;
        for(auto v:p){
            if(++mm[abs(v-x)] > m[abs(v-x)]){
                can = false; break;
            }
        }
        if(can && x>0 && x<=1000000000) cout << x << "\n";
    }
}

signed main(){
	fastio;
	solve();
}