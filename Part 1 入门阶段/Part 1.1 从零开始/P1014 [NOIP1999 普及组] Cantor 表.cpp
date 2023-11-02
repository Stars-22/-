#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int num = 1;
    int l = 1;
    int j = 1;
    while(true){
    	if(num == N)break;
    	if(j == 1){
    		while(true){
    			if(num == N)break;
    			num++;
    			j++;
    			if(l != 1) l--;
    			else break;
			}
		}
		if(num == N)break;
		num++;
		l++;
		if(j != 1) j--;
		if(j == 1){
			l++;
			num++;
			if(num == N)break;
		}
	}
    cout<<l<<'/'<<j;
    return 0;
}
