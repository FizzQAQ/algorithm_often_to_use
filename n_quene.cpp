using namespace std;

int ans;
int **a;
void n_quene(int n,int high) {
	for (int i = 0; i < n; i++) {
		if (a[high][i] == 0) {
			
			if (high == n - 1)
			{
				
				ans++;

				return;		
			}
			else
			{
				for (int j = 0; j < n; j++) {
					if(!(i==j))
					a[high][j]++;
				}
				for (int j = 0; j < n; j++) {
					if(!(j==high))
					a[j][i]++;
				}
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (!(j == high&&k==i)) {
							if (j - k == high - i)
								a[j][k] ++;
							if (j + k == high + i) {
								a[j][k] ++;
							}
						}
					}
					
				}
				n_quene(n, high + 1);
				for (int j = 0; j < n; j++) {
					if (!(i == j))
						a[high][j] --;
				}
				for (int j = 0; j < n; j++) {
					if (!(j == high))
					a[j][i] --;
				}
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (!(j == high && k == i)) {
							if (j-k == high - i)
								a[j][k] --;
							if (j + k == high + i) {
								a[j][k] --;
							}
						}
					}
				}
			}
		}
		
	}

}

