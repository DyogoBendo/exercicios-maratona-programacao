#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, current, mobile, read;
	vector<int> sidestreet;
	cin >> t;
	for (int j=0; j<t; j++){
	    cin >> n;
	    sidestreet.clear();
	    current = 1;
        read = 0;
	    string answer = "yes";
	    while (current<n+1){
	        if (!sidestreet.empty() && sidestreet.back() == current){
	            current++;
	            sidestreet.pop_back();
	        }
	        else {
	            cin >> mobile;
                read++;
	            if (current == mobile) current++;
	            else {
	                if (!sidestreet.empty() && sidestreet.back() < mobile){
	                    answer = "no";
	                    for (;read<n;read++) cin >> mobile;
                        break;
	                }
	                else sidestreet.push_back(mobile);
	            }
	        }
	    }
	    cout << answer << "\n";
	}
	return 0;
}