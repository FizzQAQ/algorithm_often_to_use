#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int n;
int* judge ;
int count1 = 0;
void dfs(int **a,int j) 
{
	for (int i = 0; i < n; i++) {
		if(a[j][i])
		if (!judge[i]) {
			judge[i] = 1;
			dfs(a, i);
			
		}
	}
	return;
}
