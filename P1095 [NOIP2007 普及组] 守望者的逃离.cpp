//Î´Íê³É 
#include <bits/stdc++.h>
using namespace std;
int main(){
	int m, s, t;
	cin >> m >> s >> t;
	int n = s / 60;
	int t0 = n;
	int t1 = (n*10-m)%4>0?(n*10-m)/4+1:(n*10-m)/4;
	int t2 = (s-n*60)%17?(s-n*60)/17+1:(s-n*60)/17;
	if(t1 < 0 ) t1 = 0;
	int t3 = t0 + t1 + t2;
	if(s % 60 != 0){
		n = s / 60 + 1;
		t0 = n;
		t1 = (n*10-m)%4>0?(n*10-m)/4+1:(n*10-m)/4;
		if(t1 < 0 ) t1 = 0;
		if(t3 > t0 + t1) t3 = t0 + t1;
	}
	if(t >= t3) cout << "Yes" << endl << t3;
	else{
		int l = m / 10 * 60;
		m = m % 10;
		l +=  (t-7) / 5 * 24;
		l = l 
		while(t > 0){
			if(m/10 > 0){
				l += 60;
				m -= 10;
			}
			else if((m+(t-1)*4) / 10 > 2 || (m+(t-1)*4) % 10 == 0){
				m += 4;
			}
			else{
				l += 17;
			}
			t --;
		}
		cout << "No" << endl << l;
	}
    return 0;
}
