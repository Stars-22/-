#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	int sum = 0;
	sum = sum + (a[0]-'0')*1 + (a[2]-'0')*2 + (a[3]-'0')*3;
	sum = sum + (a[4]-'0')*4 + (a[6]-'0')*5 + (a[7]-'0')*6;
	sum = sum + (a[8]-'0')*7 + (a[9]-'0')*8 + (a[10]-'0')*9;
	sum = sum % 11;
	if(a[12] == 'X') a[12] = 10 + '0';
	if(sum == a[12]-'0') cout<<"Right";
	else{
		if(sum == 10) a[12] = 'X';
		else a[12] = sum + '0';
		cout<<a;
	}
    return 0;
}
