#include <bits/stdc++.h>
using namespace std;
int main(){
	char a;
	int p = 0;
	bool k = true;
	while((a = getchar()) != '@'){
		if(a == '(') p++;
		if(a == ')') p--;
		if(p < 0) k = false;
	}
	if(p != 0) k = false;
	if(k) cout << "YES";
	else cout << "NO";
	return 0;
}
