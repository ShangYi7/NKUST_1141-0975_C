#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int mode = 0;
	int size = 0;

	while (scanf("%d %d", &mode, &size) == 2 && mode != -1) {
		if (size <= 0) continue;

		switch (mode) {
		case 1:
			for (int i = 0; i < size; ++i) {
				for (int j = 0; j < size - i; ++j) putchar('*');
				putchar('\n');
			}
			break;

		case 2:
			for (int i = 0; i < size; ++i) {
				for (int j = 0; j <= i; ++j) putchar('*');
				putchar('\n');
			}
			break;

		case 3:
			for (int i = 0; i < size; ++i) {
				for (int s = 0; s < size - i - 1; ++s) putchar(' ');
				for (int j = 0; j <= i; ++j) putchar('*');
				putchar('\n');
			}
			break;

		case 4:
			for (int i = 0; i < size; ++i) {
				for (int s = 0; s < i; ++s) putchar(' ');
				for (int j = 0; j < size - i; ++j) putchar('*');
				putchar('\n');
			}
			break;

		default:
			for (int i = 0; i <= size; ++i) {
				for (int j = 1; j <= size; ++j) {
					if (size - j >= i) {
						printf(" ");
					}
					else {
						printf("* ");
					}
				}
				printf("\n");
			}
			for (int i = size - 1; i >= 1; i--) {
				for (int j = 1; j <= size; j++) {
					if (size - j >= i) {
						printf(" ");
					}
					else {
						printf("* ");
					}
				}
				printf("\n");
			}
			break;
		}
	}

	return 0;
}
