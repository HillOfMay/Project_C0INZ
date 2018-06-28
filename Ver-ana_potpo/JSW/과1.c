#include <stdio.h>
#include<Windows.h>

int main() {
	int n, i, j,star,c,sum=0;
	printf("N = ");
	scanf("%d", &star);
	for (n = 1; n <= 99; n +=5) {
		for (i = 1; i <= 99; i +=5) {
			for (c = 3; c <= 3; c+=2) {
				printf("%2d %2d %2d ", n, c, i);
				sum = (100 - n)*(80 - 5 * c) / 10;
				printf("%3d ", sum);
				Sleep(50);
				if (n > i) {
					sum = (100 - n)*(100 - n + i)* (100 - n + i)*(80-5*c)/100000;
				}
				if (n <= i) {
					sum = (100 - n)*(100 + n - i) *(100 + n - i) * (80 - 5 * c) / 100000;
				}

			}
		}
	}
	/*scanf("%d %d %d", &n, &c, &i);
	sum = (100 - n)*(10 - c);
	printf("%d ", sum);
	sum = (n - i)*(n - i) / 80 * i / n;
	sum = ((100 - n)*(10 - c) - sum)*i / n;
	printf("%d\n", sum);*/

	}