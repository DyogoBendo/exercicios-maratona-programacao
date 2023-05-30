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
    while(n--){
        long long a, b;
        long long amount = 0;
        cin >> a >> b;
        //if b is prime, then amount = b-1;
        //if gcd(a, b) = 1, then we gotta find all the relatively prime numbers to b;
        //if gcd(a, b) != 1, then the only appropriate answer is 0
        if(!mark[b]){
            cout << b - 1 << endl;
            break;
        }else if(__gcd(a, b) == 1){
            for(int i = 0; i < b; i++){
                if(__gcd(a+i, b) == 1){
                    amount++;
                }
            } 
            cout << amount << endl;  
        }else{
            for(int i = a; i+i < b; i++){
                
            }
        }  
    }
}