#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int money = 0;
	int m50 = 0, m10 = 0, m5 = 0, m1 = 0;
	int item = 0;
	int item_money = 0;
	int i1 = 15, i2 = 23, i3 = 25, i4 = 37, i5 = 50;

	while (1)
	{
		scanf("%d", &m50);
		if (m50 == -1) {
			break;
		}
		scanf("%d %d %d %d", &m10, &m5, &m1, &item);
		

		money = m50*50 + m10*10 + m5*5 + m1*1;
		
		switch (item)
		{
		case 1:
			item_money = i1;
			break;
		case 2:
			item_money = i2;
			break;
		case 3:
			item_money = i3;
			break;
		case 4:
			item_money = i4;
			break;
		case 5:
			item_money = i5;
			break;
		default:
			printf("%d", money);
			break;
		}
		if (money >= item_money) {
			money = money - item_money;
			printf("get:%d,change:%d %d %d %d\n", item, money / 50, money % 50 / 10, money % 50 % 10 / 5, money % 50 % 10 % 5 / 1);
		}
		else {
			printf("get:NA,change:%d %d %d %d\n", m50, m10, m5, m1);
		}
	}
	system("PAUSE");
	return 0;
}
