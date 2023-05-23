#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n, m, mdc, k[3];
    int q;
    cin >> n >> m >> q;
    k[3], mdc = __gcd(n, m);
    k[1] = n/mdc;
    k[2] = m/mdc;
    while(q--){
        long long sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        long long a1 = sy/k[sx] + (sy%k[sx] != 0);
        long long a2 = ey/k[ex] + (ey%k[ex] != 0);
        if(a1 == a2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
