#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
int** graph;
int* judge;
struct edge {
	int l;
	int r;
	int len;
};;
class minheap {
public:
	edge* hep = new edge[400000];
	int con = 0;
	void shiftdown(int start, int m) {
		int i = start, j = i * 2 + 1;
		edge temp = hep[i];
		while (j <= m)
		{
			if (j < m && hep[j].len > hep[j + 1].len)j++;
			if (temp.len <= hep[j].len) break;
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
		edge temp = hep[j];
		while (j > 0) {
			if (hep[i].len <= temp.len) break;
			else {
				hep[j] = hep[i];
				j = i;
				i = (i - 1) / 2;
			}
			hep[j] = temp;
		}
	};
	void insert(edge a) {
		hep[con] = a;
		shiftup(con);
		con++;
	};
	edge remove() {
		edge minxx = hep[0];
		hep[0] = hep[con - 1];
		con--;
		shiftdown(0, con - 1);
		return minxx;
	};
	int size() { return con; }
};
void Dijkstra(int s, int* dist,int n) {
	minheap h1;
	dist[s] = 0;
	judge[s] = 1;
	for (int i = 0; i < n; i++) {
		if (graph[s][i] > 0) {
			edge e{s,i,graph[s][i]+dist[s]};
			h1.insert(e);
			dist[i] = graph[s][i];
		}
	}
	while (h1.size())
	{
		judge[h1.hep[0].r] = 1;
		dist[h1.hep[0].r] = min(h1.hep[0].len, dist[h1.hep[0].r]);
		for (int i = 0; i < n; i++) {
			if (graph[h1.hep[0].r][i] > 0) {
				edge e{ s,i,graph[h1.hep[0].r][i] + dist[h1.hep[0].r] };
				h1.insert(e);
			}
		}
		while (h1.size()&&judge[h1.hep[0].r])
		{
			h1.remove();
		}

	}
}
