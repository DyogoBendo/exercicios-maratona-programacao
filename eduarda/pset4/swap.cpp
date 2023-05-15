
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int size;
    char input;
    vector<int> differences, a, b;
    vector<char> s;
    vector< pair<int, int> > changes;
    cin >> size;
    for (int i=0; i<size; i++) {
        cin >> input;
        s.push_back(input);
    }
    for (int i=0; i<size; i++) {
        cin >> input;
        if (input != s[i]) differences.push_back(i);
    }
    for (int i=0; i<differences.size(); i++){
        if (s[differences[i]] == 'a') a.push_back(differences[i]);
        else b.push_back(differences[i]);
    }
    if (a.size()%2 != b.size()%2) cout << -1; 
    else{
        if (a.size()%2 == 0){
            cout << a.size()/2 + b.size()/2 << "\n";
            for (int i=0; i<a.size(); i+=2) cout << a[i]+1 << ' ' << a[i+1]+1 << "\n";
            for (int i=0; i<b.size(); i+=2) cout << b[i]+1 << ' ' << b[i+1]+1 << "\n";
        }
        else{
            cout << a.size()/2.0 + b.size()/2.0 + 1 << "\n";
            for (int i=1; i<a.size(); i+=2) cout << a[i]+1 << ' ' << a[i+1]+1 << "\n";
            for (int i=1; i<b.size(); i+=2) cout << b[i]+1 << ' ' << b[i+1]+1 << "\n";
            cout << a[0]+1 << ' ' << a[0]+1 << "\n";
            cout << a[0]+1 << ' ' << b[0]+1 << "\n";
        }
    }
}