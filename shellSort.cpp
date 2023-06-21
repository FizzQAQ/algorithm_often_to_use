void shellSort(int a[], int len) {
	for (int gap = len; gap > 0; gap /= 2)
		for (int i = gap; i < len; i++)
			for (int j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
			{
				int temp = a[j];
				a[j] = a[j + gap];
				a[j + gap] = temp;
			}

}