#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

signed main(){
	fastio;
	auto is_num = [](char c) -> bool {
		return '0'<=c and c<='9';
	};
	auto is_letter = [](char c) -> bool {
		return 'a'<=c and c<='z';
	};
	auto is_sign = [is_num, is_letter](char c) -> bool {
		return !is_num(c) and !is_letter(c);
	};
	auto is_number = [is_num](string s) -> bool {
		for(int i=0; i<s.size(); i++) {
			if(!is_num(s[i])) return false;
		}
		return true;
	};

	int n; cin>>n;
	cin>>ws;
	map<int,int> mn, mx;
	bool valid=false;
	for(int i=0; i<n; i++) {
		string s;
		getline(cin,s);
		if(valid) continue;
		for(int j=0; j<s.size() and !valid; j++) {
			string cur;
			bool has=false;
			while(j<s.size()) {
				if(is_letter(s[j])) has=true;
				if(has and is_sign(s[j])) break;
				else {
					if(is_sign(s[j])) {
						if(j and !is_num(s[j-1])) break;
						if(j+1<s.size() and !is_num(s[j+1])) break;
					}
					else cur += s[j];
					j++;
				}
			}
			if(cur.size() and is_number(cur)) {
				int x = stoll(cur);
				if(mn.count(x)) mn[x] = min(mn[x], i*20+j);
				else mn[x] = i*20+j;

				if(mx.count(x)) mx[x] = max(mx[x], i*20+j);
				else mx[x] = i*20+j;

				if(mn.count(x-2) and mx.count(x-1)) {
					if(mn[x-2] < mn[x-1]) valid=true;
				}
			}
		}
	}
	cout<<(valid? "123":":)")<<endl;
	return 0;
}