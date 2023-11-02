#include <iostream>
using namespace std;
int main(){
	char a;
	int sum = 0;
    while(cin.get(a)){
    	if(a == '\n' || a == ' ') continue;
    	sum++;
	}
	cout<<sum;
    return 0;
}
