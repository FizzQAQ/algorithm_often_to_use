int maxSubstring(int a[], int len) {
	int maxsum = a[0], maxhere = a[0];
	for (int i = 1; i < len; i++) {
		if (maxhere <= 0) {//如果之前最大子串小于0
			maxhere = a[i];//更新子串位置
		}
		else
		{
			maxhere += a[i];//如果之前子串大于0，更新新子串
		}
		maxsum = max(maxsum, maxhere);
	}
	return maxsum;

}