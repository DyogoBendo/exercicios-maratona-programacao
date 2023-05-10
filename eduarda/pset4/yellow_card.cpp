#include <bits/stdc++.h>
using namespace std;

struct limit {
    int team_amount; 
    int card_amount;
    bool operator<(const limit &l){
        return card_amount < l.card_amount;
    }
};

int main(){
    int a1, a2, k1, k2, cards;
    cin >> a1 >> a2 >> k1 >> k2 >> cards; 

    int maximum = 0;
    /*maximum*/
    vector<limit> limits = {limit {a1, k1}, limit {a2, k2}};

    sort(limits.begin(), limits.end());

    int temp = cards;
    for(int i = 0; i < 2; i++){
        while(temp >= limits[i].card_amount && limits[i].team_amount != 0){
            temp -= limits[i].card_amount;
            limits[i].team_amount--;
            maximum++;
        }
    }

    int minimum = max(0, cards - a1 *(k1 - 1) - a2*(k2 -1));

    cout << minimum << " " << maximum;

}