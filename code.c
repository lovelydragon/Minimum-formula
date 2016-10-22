#include<stdlib.h>
#include<stdio.h>

void sort(int a[], int k);
int ab(int a, int b);

#define m 10
#define n 6

int main() {
	int a[m];
	int count=0;
	int i;
	for (i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < m - n - 1; i++) {
		sort(a, m - i);
		a[m-i-2]=ab(a[m-i-2], a[m-i-1]);
	}
	for (i = 0; i < n + 1; i++) {
		printf("%d  ", a[i]);
		count = count + a[i];
	}
	printf("\n");
	printf("最小的值为：%d\n", count);
	return 0;
}


int ab(int a, int b) {
	int c, i=1;
	int j, e=1;
	while (b / 10 != 0) {
		b = b % 10;
		i++;
	}
	for (j = 0; j < i; j++)
		e *= 10;
	c = a*e + b;
	return c;
}

void sort(int a[], int k) {//k表示a[]中剩余多少个数
	int i, j;
	int temp;
	for (i = 0; i < k; i++) {
		for (j = i+1; j < k; j++) {
			if (a[i] < a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
