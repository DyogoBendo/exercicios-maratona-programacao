#include <bits/stdc++.h>
using namespace std;

#define MAX_SIEVE 100000

vector<int> primo; 
int mark[MAX_SIEVE];

void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) primo.push_back(i);
		for(int p: primo){
			if(i*p >= MAX_SIEVE) break;
			mark[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}

int main(){
    long long n;
    cin >> n;
    crivo();
    char result = 'N';
    for(int p : primo){
        if(p != n && n%p == 0){
            result = 'S';
        }
    }
    cout << result;
}