void radixSort(int a[], int len) {
	int maxx = 0, sum = 0;
	for (int i = 0; i < len; i++)
		maxx = max(a[i], maxx);
	int numCnt = 0;
	while (maxx > 0)
	{
		maxx /= 10;
		numCnt++;
	}
	vector<int> bucket[10];
	for (int i = 0; i < numCnt; i++)
	{
		for (int j = 0; j < len; j++) {
			int temp = a[j] / pow(10, i);
			temp %= 10;
			bucket[temp].push_back(a[j]);
		}
		int cnt = 0;
		for (int k = 0; k < 10; k++) {
			while (!bucket[k].empty())
			{
				a[cnt] = *bucket[k].begin();
				cnt++;
				bucket[k].erase(bucket[k].begin());
			}
		}
	}
}