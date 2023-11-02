#include <bits/stdc++.h>
using namespace std;
int n,m,k;
short int day[1001][10000];
int day_[1001];
int person[1000];
int tem;
int main(){
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
    	for(int t=0; t<m; t++){
    		cin>>tem;
    		day[tem][day_[tem]] = i;
    		day_[tem]++;
		}  
	}
	for(int i=1; i<=k; i++){
		int k_[1000];
		int k_num = 0;
		k_[0] = 0 ;
		for(int t=0; t<day_[i]; t++){
			person[day[i][t]]++;
	 		for(int p=0; p<=k_num; p++){
				if(k_[p] == 0){
					k_[p+1] = 0;
					k_[p] = person[day[i][t]];
					k_num++;
					break;
				}
				if(k_[p] == person[day[i][t]]) break;
			}
		}
		cout<<k_num<<' ';
	}
    return 0;
}
