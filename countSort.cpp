void countSort(int a[], int len) {
	int maxx = 0, sum = 0;
	for (int i = 0; i < len; i++)
		maxx = max(a[i], maxx);
	int* count = new int[maxx + 1]();
	int* temp = new int[len];
	for (int i = 0; i < len; i++) {
		count[a[i]]++;
	}
	for (int i = 0; i < maxx + 1; i++) {
		sum += count[i];
		count[i] = sum;
	}
	for (int i = 0; i < len; i++) {
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}
	for (int i = 0; i < len; i++) {
		a[i] = temp[i];
	}


}