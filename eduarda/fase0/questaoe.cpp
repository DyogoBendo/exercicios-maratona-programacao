#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<ll> guesses;
    vector<ll> mistakes;
    for (int i = 0; i < n; i++) {
        ll value;
        cin >> value;
        guesses.push_back(value);
    }
    for (int j = 0; j < n; j++) {
        ll value;
        cin >> value;
        mistakes.push_back(value);
    }

    map<ll, ll> result;
    vector<ll> answers;
    for (int i = 0; i < n; i++) {
        ll soma = guesses[i] + mistakes[i];
        ll sub = guesses[i] - mistakes[i];
        
        result[soma]++; 
        result[sub]++;

    }

    vector<pair<ll, ll>> sortedMap(result.begin(), result.end());
    sort(sortedMap.begin(), sortedMap.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.second > b.second;
    });

    auto prev = 0;
    for (const auto& pair : sortedMap) {
        if(pair.second < prev) break;
        prev = pair.second;
        cout << pair.first << endl;

    }

    return 0;
}
