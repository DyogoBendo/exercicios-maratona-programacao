#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int count_0 = 0;
    int count_1 = 0;
    vector<int> values;
    vector<string> names = {"A", "B", "C"};
    for(int i = 0; i < 3; i++){
        int x; 
        cin >> x;
        values.push_back(x);
        if(x == 0){
            count_0++;
        }else{
            count_1++;
        }  
    }
 
    if(count_0 == 3 || count_1 == 3){
        cout << "*";
    }
    else if(count_0 > count_1){
        for(int i = 0; i < 3; i++){
            if(values[i] == 1){
                cout<< names[i];
            }
        }
    }else if(count_1 > count_0){
        for(int i = 0; i < 3; i++){
            if(values[i] == 0){
                cout<< names[i];
            }
        }
    }
 
}