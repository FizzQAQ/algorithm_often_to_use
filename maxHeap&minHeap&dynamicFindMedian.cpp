#include<iostream>
#include<cmath>
using namespace std;

class minheap {
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
	int size() { return con; }
};
class maxheap {
public:
	int* hep = new int[400000];
	int con = 0;
	void shiftdown(int start, int m) {
		int i = start, j = i * 2 + 1;
		int temp = hep[i];
		while (j <= m)
		{
			if (j < m && hep[j] < hep[j + 1])j++;
			if (temp >= hep[j]) break;
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
			if (hep[i] >= temp) break;
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
	int size() { return con; }
};



int main() {
    int n;
	minheap minh;
	maxheap maxh;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
		if (i % 2 == 0) {
			minh.insert(a[i]);
			if (minh.hep[0] < maxh.hep[0]) {
				maxh.insert(minh.remove());
				minh.insert(maxh.remove());
			}
			cout << minh.hep[0] << endl;
		}
		else
		{
			maxh.insert(a[i]);
			if (minh.hep[0] < maxh.hep[0]) {
				maxh.insert(minh.remove());
				minh.insert(maxh.remove());
			}
		}
		
    }
    
}
