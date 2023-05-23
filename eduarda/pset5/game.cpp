#include <bits/stdc++.h>
using namespace std;
 
#define MAX_SIEVE 1000000
 
vector<int> primo; 
bitset<10000001> mark;
 
void crivo(){
	for(int i = 2; i < MAX_SIEVE; i++){
		if(!mark[i]) {
            primo.push_back(i);
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
    vector<int> ans;
    crivo();
    for(int i = 0; i <= n; i++){
        int q = 1;
        while(q <= n/primo[i]){
            q *= primo[i];
            ans.push_back(q);
        }
    }
    cout << ans.size() << endl;
    for(auto value : ans){
        cout << value << " ";
    }
}
 