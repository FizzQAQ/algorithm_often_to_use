int maxSubstring(int a[], int len) {
	int maxsum = a[0], maxhere = a[0];
	for (int i = 1; i < len; i++) {
		if (maxhere <= 0) {//���֮ǰ����Ӵ�С��0
			maxhere = a[i];//�����Ӵ�λ��
		}
		else
		{
			maxhere += a[i];//���֮ǰ�Ӵ�����0���������Ӵ�
		}
		maxsum = max(maxsum, maxhere);
	}
	return maxsum;

}