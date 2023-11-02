#include <bits/stdc++.h>
using namespace std;
int ans[21][21][21];
void draw(){
	for(int i=0; i<=20; i++){
		for(int t=0; t<=20; t++){
			ans[0][i][t] = 1;
			ans[i][0][t] = 1;
			ans[i][t][0] = 1;
		}
	}
	for(int o=1; o<=20; o++){
		for(int p=1; p<=20; p++){
			for(int q=1; q<=20; q++){
				ans[o][p][q] = ans[o-1][p][q] + ans[o-1][p-1][q] + ans[o-1][p][q-1] - ans[o-1][p-1][q-1];
			}
		}
	}
}
int main(){
	draw();
	long long a, b, c;
	while(true){
		cin >> a >> b >> c;
		if(a==-1 && b==-1 && c==-1)break;
		long long d = a;
		long long e = b;
		long long f = c;
		if(d<=0 || e<=0 || f<=0){
			d = 0;
			e = 0;
			f = 0;
		}
		if(d>20 || e>20 || f>20){
			d = 20;
			e = 20;
			f = 20;
		}
		if(d<e && e<f) printf("w(%ld, %ld, %ld) = %d\n", a, b, c, ans[d][e][f-1]+ans[d][e-1][f-1]-ans[d][e-1][f]);
		else printf("w(%ld, %ld, %ld) = %d\n", a, b, c, ans[d][e][f]);
	}
    return 0;
}
