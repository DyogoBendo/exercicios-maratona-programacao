#include <bits/stdc++.h>
using namespace std; 

int fib(int n){
    if(n <= 1){
        return n;
    }else{
        int prev = 0;
        int current = 1;
        for(int i = 2; i <= n; i++){
            int next = prev + current;
            prev = current;
            current = next;
        }
        return current;
    }
}

int main(){
    int n, result;
    cin >> n;

    result = fib(n+1);
    cout << result;
}