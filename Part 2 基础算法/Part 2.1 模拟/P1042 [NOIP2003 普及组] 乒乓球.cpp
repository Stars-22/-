#include <bits/stdc++.h>
using namespace std;
char a[70000];
void ans(int m){
	int s1 = 0, s2 = 0;
	for(int i=0; ; i++){
		if(a[i] == '\n') continue;
		if(a[i] == 'W') s1 ++;
		if(a[i] == 'L') s2 ++;
		if((s1-s2>=2 || s2-s1 >=2) && (s1>=m || s2>=m)){
			cout << s1 << ':' << s2 << endl;
			s1 = 0;
			s2 = 0;
			continue;
		}
		if(a[i] == 'E'){
			cout << s1 << ':' << s2 << endl;
			break;
		}
	}
}
int main(){
	int n = 0;
	while(cin.get(a[n]))
		if(a[n++] == 'E') break;
	ans(11);
	cout << endl;
	ans(21);
    return 0;
}
