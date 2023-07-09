#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, r;
    cin >> n >> r;
    vector<bool> check(n + 1,false);
 
    for(int i = 1; i < r + 1; i++){
        int a;
        cin >> a;
        check[a] = true;
    }
 
    bool count = true;
    for(int i = 1; i <= n; i++){
        if(!check[i]){
            cout << i << " ";
            count = false;
        }
    }
 
    if(count) cout << "*";
    
}