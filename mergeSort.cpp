void megersort(int *tosort,int*temp,int start,int end) {
	int mid = (start + end) / 2;
	int s1 = start, e1 = mid, s2 = mid + 1, e2 = end;
	if (end <= start) {
		return;
	}
	megersort(tosort, temp, s1, e1);
	megersort(tosort, temp, s2, e2);
	int cnt = s1;
	while (s1<=e1&&s2<=e2)
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
	while (s2<=e2)
	{
		temp[cnt] = tosort[s2];
		s2++;
		cnt++;

	}
	for (int i = start; i <= end; i++) {
		tosort[i] = temp[i];
	}
	
}
void mSort(int* a, int len) {
	int* b = new int[len];
	megersort(a, b, 0, len - 1);
}
