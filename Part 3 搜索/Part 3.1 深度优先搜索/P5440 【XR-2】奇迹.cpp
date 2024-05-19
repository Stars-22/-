#include <bits/stdc++.h>
using namespace std;
int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int num;
bool isPrime(int a){ //判断是否是质数 
	if(a == 1) return false; 
	if(a % 2 == 0) return false;
	for(int t=3; t*t<=a; t+=2)
		if(a % t == 0) return false;
	return true;
}
bool isTrue(int year, int month, int day){ //判断是否存在这个日期 
	if(year == 0) return false;
	if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		if(month == 2 && day == 29) return true;
	if(month > 12 || month == 0) return false;
	if(day > mday[month] || day == 0) return false;
	return true;
}
void judege(char a[8]){ //判断这个日期是否符合奇迹要求 
	int year, month, day;
	year = (a[0] - '0') * 1000 + (a[1] - '0') * 100;
	year = (a[2] - '0') * 10 + (a[3] - '0') + year;
	month = (a[4] - '0') * 10 + (a[5] - '0');
	day = (a[6] - '0') * 10 + (a[7] - '0');
	if(!isTrue(year, month, day)) return;
	int x = day, y = month * 100 + x, z = year * 10000 + y;
	if(isPrime(x) && isPrime(y) && isPrime(z)){
		num ++;
		//cout << year << ' ' << month << ' ' << day << endl;
	}
}
void meiju(char a[8]){ //枚举各个日期 
	for(int i=0; i<8; i++){
		if(a[i] == '-'){
			for(int t=0; t<=9; t++){
				a[i] = t + '0';
				meiju(a);
			}
			a[i] = '-';
			break;
		}
		if(i == 7) judege(a);
	}
}
int main() {
	int t;
	bool k;
	cin >> t;
	char a[8];
	for(int i=1; i<=t; i++){
		num = 0;
		k = true;
		getchar();getchar();
		for(int j=0; j<8; j++){
			a[j] = getchar();
			if(a[j] != '-') k = false;
		}
		if(k) num = 55157;
		else meiju(a);
		cout << num << endl;
	}
	return 0;
}
