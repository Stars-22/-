#include <bits/stdc++.h>
using namespace std;
int main()
{
    int pay[12];
    int sum = 0;
    bool poor = false;
    for(int i=0; i<12; i++){
    	cin>>pay[i];
    	if(pay[i] > sum%100 + 300){
    		cout<<-i-1;
    		return 0;
		}
		sum = sum + 300 - pay[i];
	}
	cout<<sum/100*120+sum%100;
    return 0;
}
