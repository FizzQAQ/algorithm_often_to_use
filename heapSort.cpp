class heap {
public:
	int* hep = new int[400000];
	int con = 0;
	void shiftdown(int start, int m) {
		int i = start, j = i * 2 + 1;
		int temp = hep[i];
		while (j <= m)
		{
			if (j < m && hep[j] > hep[j + 1])j++;
			if (temp <= hep[j]) break;
			else
			{
				hep[i] = hep[j];
				i = j;
				j = i * 2 + 1;
			}
			hep[i] = temp;
		}
	}
	void shiftup(int start) {
		int j = start, i = (j - 1) / 2;
		int temp = hep[j];
		while (j > 0) {
			if (hep[i] <= temp) break;
			else {
				hep[j] = hep[i];
				j = i;
				i = (i - 1) / 2;
			}
			hep[j] = temp;
		}
	};
	void insert(int a) {
		hep[con] = a;
		shiftup(con);
		con++;
	};
	int remove() {
		int minxx = hep[0];
		hep[0] = hep[con - 1];
		con--;
		shiftdown(0, con - 1);
		return minxx;
	};
};
void heapSort(int a[], int len) {
	heap he;
	for (int i = 0; i < len; i++) {
		he.insert(a[i]);
	}
	for (int i = 0; i < len; i++) {
		a[i] = he.remove();
	}
}