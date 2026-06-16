#include <stdio.h>
#include <string.h>

int main() {
    // 直接測試輸入
    const char* tests[] = {"A", "(A+B)*C", "[A+B]*{C+D}"};

    for (int t = 0; t < 3; t++) {
        FILE* fp = popen("echo test | echo %s > tmp.txt", "w");
        // 簡單地輸出測試字符串
        printf("Test %d: %s\n", t+1, tests[t]);
    }

    return 0;
}
