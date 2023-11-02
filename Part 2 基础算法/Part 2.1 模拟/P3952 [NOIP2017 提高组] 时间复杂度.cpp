#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int l, num;
	cin >> n;
	for(int i=1; i<=n; i++){
		bool e = false;
		num = 0;
		cin >> l;
		cin.get(); cin.get(); cin.get();
		char a;
		cin.get(a);
		if(a != 'n'){
			cin.get();
		}
		if(a == 'n'){
			cin.get();
			string a1;
			cin >> a1;
			a1.erase(a1.size()-1);
			for(int t=0; t<a1.size(); t++){
				num = num + (a1[t]-'0') * pow(10, a1.size()-t-1);
			}
		}
		int sum = 0;
		int ans = 0;
		string iname[101];
		string xname[101];
		string yname[101];
		int lname = 0;
		bool k = false;
		char b;
		int sum1[101];
		int k_ = -1;
		for(int t=1; t<=l; t++){
			cin >> b;
			if(b == 'F'){
				cin >> iname[lname] >> xname[lname] >> yname[lname];
				for(int o=0; o<lname; o++){
					if(iname[lname] == iname[o]) e = true;
				}
				if(xname[lname] != "n" && yname[lname] != "n" && !k){
					int x , y;
					if(xname[lname].size() == 2) x = (xname[lname][0]-'0')*10 + xname[lname][1]-'0';
					else x = xname[lname][0] - '0';
					if(yname[lname].size() == 2) y = (yname[lname][0]-'0')*10 + yname[lname][1]-'0';
					else y = yname[lname][0] - '0';
					if(x > y){
						k = true;
						k_ = lname;
					}
				}
				if(xname[lname] == "n" && yname[lname] != "n" && !k){
					k = true;
					k_ = lname;
				}
				if(xname[lname] != "n" && yname[lname] == "n" && !k){
					if(sum == ans){
						sum ++; ans ++;
					}
					else sum ++;
				}
				sum1[lname] = sum;
				lname ++;
			}
			if(b == 'E'){
				if(k_ == lname){
					k = false;
					k_ = -1;
				}
				if(lname == 0) e = true;
				if(lname > 0) lname --;
				if(lname != 0) sum = sum1[lname-1];
				else sum = 0;
			}
		}
		
		if(lname != 0 ) e = true;
		if(!e){
			if(ans == num) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else cout << "ERR" << endl;
	}
    return 0;
}
