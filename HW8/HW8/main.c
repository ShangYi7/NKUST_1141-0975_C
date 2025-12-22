#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 程そ计
int factor(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

// 程そ计
int multiple(int a, int b) {
	int temp = 1;
	int ans = 0;
	while (1) {
		if (temp % a == 0 && temp % b == 0)
		{
			ans = temp;
			return ans;
		}
		temp++;
	}

}

int main() {
	int mode;
	int a, b;
	while (1)
	{
		scanf("%d", &mode);
		if (mode == -1) {
			return 0;
		}
		scanf("%d %d", &a, &b);

		switch (mode) {
			case 1:
				printf("%d\n", factor(a, b));
				break;
			case 2:
				printf("%d\n", multiple(a, b));
				break;
		}
	}
	return 0;
}

