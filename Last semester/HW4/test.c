int main() {
	int ans = 0;
	int min = 1 ,max = 100;
	int data = 0;

	scanf("%d", &ans);
	printf("%d~%d\n", min, max);
	while (1) {
		scanf("%d", &data);
		if (data == ans) {
			break;
		}
		if (ans < data) {
			max = data - 1;
		}
		else if(ans>data) {
			min = data + 1;
		}
		printf("%d~%d\n", min, max);
	}
	printf("PASS\n");
}