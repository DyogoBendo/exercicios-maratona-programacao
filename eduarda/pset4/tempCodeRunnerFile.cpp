#include <bits/stdc++.h>
using namespace std;

struct dragon {
    int strength; 
    int power_up;
    bool operator<(const dragon &dr){
        return strength < dr.strength;
    }
};

int main(){
    string result = "YES";
    int n, s, forca, power_up; 
    cin >> n >> s;
    vector<dragon> dragons;
    dragon dragon1;
    for(int i = 0; i < n; i++){
        cin >> forca >> power_up; 
        dragon1.strength = forca;
        dragon1.power_up = power_up;
        dragons.push_back(dragon1);
    }

    sort(dragons.begin(), dragons.end());

    for(int i = 0; i < n; i++){
        if(s >= dragons[i].strength){
            s+= dragons[i].power_up;
        }else result = "NO";
    }

    cout << result;
}