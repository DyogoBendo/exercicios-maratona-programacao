#include <bits/stdc++.h>
using namespace std; 

int main(){
    //quadrados fazem n+1 intersecções sendo n o valor do quadrado
    //retângulos de lados n e n*2 fazem n-1 intersecções;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2, base, altura;
        cin >> x1 >> y1 >> x2 >> y2;
        base = x1 - x2;
        altura = y1 - y2;
        if(base == altura){
            cout << base + 1 << endl;
        }else if(base == altura*2 || altura == base * 2){
            cout << altura - 1 << endl;
        }else{
            cout << 2;
        }
    }

}