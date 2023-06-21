#include<iostream>
using namespace std;
void swap(int* a, int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
void insert_sort(int *a,int l,int h ) {
    for (int i = l + 1; i <= h; i++)
    {
        if (a[i - 1] > a[i])
        {
            int t = a[i];
            int j = i;
            while (j > l && a[j - 1] > t)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = t;
        }
    }

}

int FindMid(int a[], int l, int r)
{
    if (l == r) return l;
    int i = 0;
    int n = 0;
    for (i = l; i < r - 5; i += 5)
    {
        insert_sort(a, i, i + 4);
        n = i - l;
        swap(a,l + n / 5, i + 2);
    }

    //处理剩余元素
    int num = r - i + 1;
    if (num > 0)
    {
        insert_sort(a, i, i + num - 1);
        n = i - l;
        swap(a,l + n / 5, i + num / 2);
    }
    n /= 5;
    if (n == l) return l;
    return FindMid(a, l, l + n);
}
int Partion(int a[], int l, int r, int p)
{
    swap(a,p, l);
    int i = l;
    int j = r;
    int pivot = a[l];
    while (i < j)
    {
        while (a[j] >= pivot && i < j)
            j--;
        a[i] = a[j];
        while (a[i] <= pivot && i < j)
            i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}
int BFPRT(int a[], int l, int r, int k)
{
    int p = FindMid(a, l, r);    //寻找中位数的中位数
    int i = Partion(a, l, r, p);

    int m = i - l + 1;
    if (m == k) return a[i];
    if (m > k)  return BFPRT(a, l, i - 1, k);
    return BFPRT(a, i + 1, r, k - m);
}
