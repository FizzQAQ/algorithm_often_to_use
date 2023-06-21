#include<cmath>
long long CombinationNumber(long long n, long long i) {
	long long ans = 1;
	int cnt = i;
	for (int j = 0; j < cnt; j++) {
		ans *= n;
		n--;
	}
	for (int j = 0; j < cnt; j++) {
		ans /= j+1;
	}
	return ans;
}
long double twomArrage(int num,long double p,int i) {
	long double ans = 1;
	return ans * CombinationNumber(num, i) * pow(p, i) * pow((1 - p), num - i);
}
long double twoArrageSum(int num, long double p, int i) {
	long double ans = 0;
	for (int j = 0; j <= i; j++) {
		ans += twomArrage(num,p,j);
	}
	return ans;
};

