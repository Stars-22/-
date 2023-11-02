#include <bits/stdc++.h>
using namespace std;
struct Money{
	string name;
	int CJ;
	int PY;
	bool GB;
	bool XB;
	int LW;
};
Money a[101];
int countGetM(int i){
	int sum = 0;
	if(a[i].CJ > 80 && a[i].LW > 0) sum = sum + 8000;
	if(a[i].CJ > 85 && a[i].PY > 80) sum = sum + 4000;
	if(a[i].CJ > 90) sum = sum + 2000;
	if(a[i].CJ > 85 && a[i].XB) sum = sum + 1000;
	if(a[i].PY > 80 && a[i].GB) sum = sum + 850;
	return sum;
}
int main(){
	int n;
	cin >> n;
	int mMax = 0;
	int mMaxI;
	int sum = 0;
	for(int i=0; i<n; i++){
		cin >> a[i].name >> a[i].CJ >> a[i].PY;
		char ganbu, xibu;
		cin >> ganbu >> xibu >> a[i].LW;
		if(ganbu == 'Y') a[i].GB = true;
		else a[i].GB = false;
		if(xibu == 'Y') a[i].XB = true;
		else a[i].XB = false;
		int getM = countGetM(i);
		sum = sum + getM;
		if(mMax < getM){
			mMax = getM;
			mMaxI = i;
		}
	}
	cout << a[mMaxI].name << endl;
	cout << mMax << endl;
	cout << sum;
    return 0;
}
