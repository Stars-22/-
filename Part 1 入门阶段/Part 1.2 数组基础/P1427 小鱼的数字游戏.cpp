#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a[100];
    int num = 0;
    while(true){
    	cin>>a[num];
    	if(a[num] == 0) break;
    	num++;
	}
	num--;
	for(int i=num; i>=0; i--){
		cout<<a[i]<<' ';
	}
    return 0;
}
