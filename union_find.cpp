int find(int* list,int i) {
	if (list[i] == i)return i;
	else return find(list, list[i]);
}
void merge(int* list, int i,int j) {
	list[find(list, j)] = find(list, i);
}