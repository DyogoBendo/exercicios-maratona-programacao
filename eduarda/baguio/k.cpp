#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " fine, thanks" << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fs first
#define sc second

#define all(x) x.begin(),x.end()

#define int ll
using ll = long long;
#define endl '\n'

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define NOSIR {cout << "NO" << endl; return;}
#define YESIR {cout << "YES" << endl; return;}

const int MOD = 1e9+7;
const int MAXN = 220;

int quarta[MAXN];
vector<tuple<int,int,int>> v;

void prec(){
    FOR(i, MAXN) FOR(j, MAXN){
        v.eb(quarta[i]+quarta[j],i,j);
    }
    sort(all(v));
}

void solve(){
    int n; cin >> n;
    set<tuple<int,int,int,int>> s;
    for(int i=0,j=v.size()-1;i<v.size() and j>=0;){
        auto [si,ai,bi] = v[i];
        auto [sj,aj,bj] = v[j];
        if(si > sj) break; 
        int ii=i;
        while(ii<v.size() && get<0>(v[i]) == get<0>(v[ii])) ii++;
        int jj=j;
        while(jj>=0 && get<0>(v[j]) == get<0>(v[jj])) jj--;
        if(si+sj > n){
            j = jj;
            continue;
        }
        if(si+sj < n){
            i = ii;
            continue;
        }
        for(int vi=i;vi<ii;vi++){
            for(int vj=j;vj>jj;vj--){
                int vv[4] = {get<1>(v[vi]),get<2>(v[vi]),get<1>(v[vj]),get<2>(v[vj])};
                sort(vv,vv+4);
                s.insert({vv[0],vv[1],vv[2],vv[3]});
            }
        }
        i = ii; j = jj;
    }
    cout << s.size() << endl;
    for(auto [a,b,c,d]:s){
        cout << a << " " << b << " " << c << " " << d << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    FOR(i, MAXN) quarta[i] = i*i*i*i;
    prec();
    int t; cin >> t; while(t--) solve();
    return 0;
}