#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, dist[100001], total=0, l, result=0;
    bitset<100001> m;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> dist[i];
        total+=dist[i];
    }
    l = total/3;
    int start = 0, d=0;
    for (int i=0; i<n-1; i++){
        d += dist[i];
 
        while (d > l){
            d -= dist[start];
            start++;
        }
 
        if (d == l){
            m[i+1] = 1;
            if (m[start]) result++;
        }
    }
    if (total%3 != 0) result = 0;
    cout << result;
}