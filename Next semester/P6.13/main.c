#include <stdio.h>

#define SIZE 5

/* 先宣告函式原型，方便 main 先呼叫後面的函式。 */
void modifyArray(int b[], size_t size);
void modifyElement(int e);

int main(void)
{
	int a[SIZE] = {0, 1, 2, 3, 4};
	size_t i;

	/* 顯示原始陣列內容。 */
	puts("以參照方式傳遞整個陣列的效果：\n原始陣列的值為：");

	/* 逐一輸出陣列元素。 */
	for (i = 0; i < SIZE; ++i) {
		printf("%3d", a[i]);
	}
	puts("");

	/* 將整個陣列傳給函式，函式會直接修改原陣列。 */
	modifyArray(a, SIZE);

	/* 顯示被 modifyArray 修改後的結果。 */
	puts("修改後陣列的值為：");

	/* 再次輸出陣列元素，確認內容已改變。 */
	for (i = 0; i < SIZE; ++i) {
		printf("%3d", a[i]);
	}
	puts("");

	/* 示範單一陣列元素以值傳遞 (pass by value) 的效果。 */
	printf("\n\n以值傳遞方式傳遞 a[3] 陣列元素的效果：");
	printf("\n呼叫前 a[3] 的值為 %d\n", a[3]);

	/* 傳入的是 a[3] 的值，不是位址，所以原陣列不會被改變。 */
	modifyElement(a[3]);

	/* 呼叫結束後再看一次 a[3]，確認沒有被函式內部改到。 */
	printf("呼叫後 a[3] 的值為 %d\n", a[3]);
}

/* 這個函式接收整個陣列，並把每個元素乘以 2。 */
void modifyArray(int b[], size_t size)
{
	size_t j;

	/* 陣列在函式中可直接用索引存取並修改。 */
	for (j = 0; j < size; ++j) {
		b[j] *= 2;
	}
}

/* 這個函式只接收單一整數，修改的是副本，不影響原變數。 */
void modifyElement(int e)
{
	/* 印出參數初值，讓你看到傳進來的是一份拷貝。 */
	printf("在 modifyElement 中，e 的初值為 %d", e);
	e *= 2;
	/* e 的改動只存在函式內部。 */
	printf("，乘以 2 後 e 的值為 %d\n", e);
}
