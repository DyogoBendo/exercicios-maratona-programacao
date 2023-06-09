#include <bits/stdc++.h>
using namespace std;
 
#define MAX_SIEVE 1000000
 
vector<int> primo; 
vector<long long> tprimes;
bitset<10000001> mark;
 
void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) {
            primo.push_back(i);
            tprimes.push_back((long long)i*i);
        };
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
    crivo();
    for(int i = 0; i < n; i++){
        long long value;
        cin >> value;
        if(binary_search(tprimes.begin(), tprimes.end(), value)) {
            cout << "YES" << endl;
            continue;
        }else{
            cout << "NO" << endl;
        }
    }

}