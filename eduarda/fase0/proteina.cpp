#include <bits/stdc++.h>
using namespace std;

int countSubstringOccurrences(const string& dna, const string& protein) {
    int count = 0;
    int dnaSize = dna.size();
    int proteinSize = protein.size();

    int i = 0, j = 0;
    while (i < dnaSize) {
        if (dna[i] == protein[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }

        if (j == proteinSize) {
            count++;
            j = 0;
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