#include <bits/stdc++.h>
using namespace std;
int main(){
	string start, stop;
	cin>> start >> stop;
	int year1, month1, day1;
	int year2, month2, day2;
	int m, d, mmax, dmax;
	int sum = 0;
	year1 = (start[0]-'0')*1000 + (start[1]-'0')*100 + (start[2]-'0')*10 + (start[3]-'0');
	month1 = (start[4]-'0')*10 + (start[5]-'0');
	day1 = (start[6]-'0')*10 + (start[7]-'0');
	year2 = (stop[0]-'0')*1000 + (stop[1]-'0')*100 + (stop[2]-'0')*10 + (stop[3]-'0');
	month2 = (stop[4]-'0')*10 + (stop[5]-'0');
	day2 = (stop[6]-'0')*10 + (stop[7]-'0');
	for(int y=year1; y<=year2; y++){
		if(y == year2) mmax = month2;
		else mmax = 12;
		if(y == year1) m = month1;
		else m = 1;
		for(; m<=mmax; m++){
			if(y == year2 && m == month2) dmax = day2;
			else if(m == 2){
				if(y % 400 == 0) dmax = 29;
				else if(y % 4 == 0 && y % 100 != 0) dmax = 29;
				else dmax = 28;
			}
			else if(m==4 || m==6 || m==9 || m==11) dmax = 30;
			else dmax = 31;
			if(y == year1 && m == month1) d = day1;
			else d = 1;
			for(; d<=dmax; d++){
				if(d%10 == y/1000){
					if(d/10 == y/100%10){
						if(m%10 == y/10%10){
							if(m/10 == y%10){
								sum++;
							}
						}
					}
				}
			}
		}
	}
	cout << sum;
    return 0;
}
