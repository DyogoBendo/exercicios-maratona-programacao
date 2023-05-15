#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> values;

    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        values.push_back(value);
    }

    map<int, int> counter;
    for(int item : values){
        counter[item]++;
    }

    pair<int, int> most_common = {0, 0};

    for(auto item : counter){
        if(item.second > most_common.second){
            most_common = item;
        }
    }

    cout << most_common.first;
}