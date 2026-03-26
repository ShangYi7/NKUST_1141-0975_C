#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int input;
	float sum;
	int s = 0, a = 0, b = 0, c = 0;

	while (true)
	{
		scanf("%d", &input);
		if (input == -1) {
			break;
		}

		if (input == 100){
			s++;
		}
		else if(input >=80)
		{
			a++;
		}
		else if (input >= 60) {
			b++;
		}
		else if (input < 60) {
			c++;
		}

		if (s > 1) {
			printf("S=%d", s);
		}

	}
 }