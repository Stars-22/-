#include <bits/stdc++.h>
using namespace std;
int main(){
	string a, b, c;
	getline(cin, a);
	getline(cin, b);
	int sum = 0;
	int k = -1;
	int k_ = -1;
	for(int i=0; i<a.size(); i++){
		if(a[i] >= 'A' && a[i] <= 'Z') a[i] = a[i] - 'A' + 'a';
	}
	for(int i=0; i<b.size(); i++){
		if(b[i] == ' '){
			if(c == a){
				sum++;
				if(k == -1) k = k_;
			}
			else k_ = -1;
			c.clear();
			continue;
		}
		if(k_ == -1) k_ = i;
		if(b[i] >= 'A' && b[i] <= 'Z') b[i] = b[i] - 'A' + 'a';
		c = c + b[i];
		if(i == b.size() && c == a) sum++;
	}
	if(sum == 0) cout<<"-1";
	else cout<<sum<<' '<<k;
    return 0;
}
