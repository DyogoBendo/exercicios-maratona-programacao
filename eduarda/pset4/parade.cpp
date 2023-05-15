#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int loops; 
    cin >> loops;
    for(int i = 0; i < loops; i++){
        int n;
        cin >> n;
        stack<int> stackers;
        int proximo = 1;
        for(int j = 0; j < n; j++){
            int current_car;
            cin >> current_car;
            if(current_car == proximo){
                proximo++;
            }else{
                stackers.push(current_car);
            }

            if(!stackers.empty() && stackers.top() == proximo){
                stackers.pop();
                proximo++;
            }
        }

        if(stackers.empty()){
            cout << "yes";
        }else{
            cout << "no";
        }
    }
}