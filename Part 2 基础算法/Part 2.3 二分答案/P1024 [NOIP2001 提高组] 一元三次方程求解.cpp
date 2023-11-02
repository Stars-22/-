#include <bits/stdc++.h>
using namespace std;
int main(){
	float a, b, c, d;
	cin >> a >> b >> c >> d;
	double ans1, ans2;
	ans2 = a*-100*-100*-100+b*-100*-100+c*-100+d;
	for(double i=-100; i<=100; i+=0.001){
		ans1 = a*i*i*i+b*i*i+c*i+d;
		if(ans1 * ans2 < 0){
			printf("%.2f ", i-0.001);
		}
		ans2 = ans1;
	}
    return 0;
}
