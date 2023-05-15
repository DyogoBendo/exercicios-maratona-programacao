#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, sumTime;
    vector<int> values, min;
    string result = "YES";
    cin >> n >> sumTime;
    for(int i = 0; i < n; i++){
        int minimum, maximum;
        cin >> minimum >> maximum;
        sumTime -= minimum;
        values.push_back(maximum-minimum);
        min.push_back(minimum);
    }

    if (sumTime < 0){
        result = "NO";
    }

    for (int i = 0; i < n; i++){
        if (sumTime <= 0) break;
        else if (sumTime >= values[i]){
            sumTime -= values[i];
            min[i] += values[i];
        }
        else{
            min[i] += sumTime;
            sumTime = 0;
        }
    }

    if (sumTime > 0){
        result = "NO";
    }
    
    cout << result << "\n";
    if (result == "YES"){
        for (int i = 0; i < n; i++) cout << min[i] << " ";
    }
}