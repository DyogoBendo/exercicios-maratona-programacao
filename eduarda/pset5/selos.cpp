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
    int n;
    cin >> n;
    long long a,b,c;
    cin >> a >> b >> c;
    vector<long long> values = {a, b, c};
    crivo();
    for(auto v : values){
        for(int p : primo){
            if(sqrt(v) < p) break;
            else if(sqrt(v) == p) {
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    
}