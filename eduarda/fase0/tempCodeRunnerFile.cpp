#include <bits/stdc++.h>
using namespace std;

int countSubstringOccurrences(const string& dna, const string& protein) {
    int count = 0;
    int a, b;
    a = 0; 
    b = protein.size();

    int i = 0, j = 0;
    while(j != dna.size()){
        if(i + j < protein.size()){
            j++;
        }
        else if(i + j > protein.size()){
            i--;
        }else{
            string s = dna.substr(i, j);
            if(s == protein) count++;
            else i++, j++;
        }
    }

    return count;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    string dna, protein;
    cin >> dna >> protein;

    int queries;
    cin >> queries;

    vector<int> answers;

    for (int i = 0; i < queries; i++) {
        int A, B;
        cin >> A >> B;
        string substring = protein.substr(A - 1, B - A + 1);
        int occurrences = countSubstringOccurrences(dna, substring);
        answers.push_back(occurrences);
    }

    for(auto a : answers){
        cout << a << endl;
    }

    return 0;
}