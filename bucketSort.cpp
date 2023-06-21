#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int a[100000];
void megersort(int* tosort, int* temp, int start, int end) {
	int mid = (start + end) / 2;
	int s1 = start, e1 = mid, s2 = mid + 1, e2 = end;
	if (end <= start) {
		return;
	}
	megersort(tosort, temp, s1, e1);
	megersort(tosort, temp, s2, e2);
	int cnt = s1;
	while (s1 <= e1 && s2 <= e2)
	{
		if (tosort[s1] <= tosort[s2]) {
			temp[cnt] = tosort[s1];
			s1++;
			cnt++;
		}
		else
		{
			temp[cnt] = tosort[s2];
			s2++;
			cnt++;
		}

	}
	while (s1 <= e1) {
		temp[cnt] = tosort[s1];
		s1++;
		cnt++;

	}
	while (s2 <= e2)
	{
		temp[cnt] = tosort[s2];
		s2++;
		cnt++;

	}
	for (int i = start; i <= end; i++) {
		tosort[i] = temp[i];
	}

}
void bucketSort(int a[], int len) {
	int maxx = 0;
	for (int i = 0; i < len; i++) {
		maxx = max(a[i], maxx);
	}
	int bucketNum = maxx / 100 + 1;
	int** newArry = new int*[bucketNum];
	for (int i = 0; i < bucketNum; i++) {
		newArry[i] = new int[len];
	}
	int* numArry = new int[bucketNum]();
	for (int i = 0; i < len; i++) {
		int temp = a[i] / 100;
		newArry[temp][numArry[temp]] = a[i];
		numArry[temp]++;
	}
	int* temp;
	for (int i = 0; i < bucketNum; i++) {
		temp = new int[numArry[i]];
		megersort(newArry[i], temp,0,numArry[i]-1);
		delete[]temp;
	}
	int cnt = 0;
	for (int i = 0; i < bucketNum; i++) {
		for (int j = 0; j < numArry[i]; j++)
		{
			a[cnt] = newArry[i][j];
			cnt++;
		}
	}

}
int main() {
	int i = 0;
	while (cin>>a[i])
	{
		if (a[i] == -1)
			break;
		i++;
	}
	bucketSort(a, i);
	for (int j = 0; j < i; j++)
	{
		cout << a[j] << " ";
	}
}

