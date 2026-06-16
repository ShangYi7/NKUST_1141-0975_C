#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE 1000
#define MAX_STACK 1000

typedef enum {
    OPERAND,    // 期待操作數或左括號
    OPERATOR    // 期待運算子或右括號
} State;

int main() {
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        // 移除換行符和回車符
        line[strcspn(line, "\r\n")] = '\0';

        if (strlen(line) == 0) continue;  // 略過空行

        State state = OPERAND;
        char stack[MAX_STACK];
        int stack_top = -1;
        int paren_count = 0, bracket_count = 0, brace_count = 0;
        int valid = 1;

        for (int i = 0; line[i] != '\0' && valid; i++) {
            char c = line[i];

            if (state == OPERAND) {
                // 期待變數或左括號
                if (c >= 'A' && c <= 'Z') {
                    // 變數
                    state = OPERATOR;
                } else if (c == '(' || c == '[' || c == '{') {
                    // 左括號
                    stack[++stack_top] = c;
                    if (c == '(') paren_count++;
                    else if (c == '[') bracket_count++;
                    else if (c == '{') brace_count++;
                    // 狀態保持為 OPERAND
                } else {
                    valid = 0;
                }
            } else { // state == OPERATOR
                // 期待運算子或右括號
                if (c == '+' || c == '*') {
                    state = OPERAND;
                } else if (c == ')' || c == ']' || c == '}') {
                    // 檢查括號匹配
                    if (stack_top < 0) {
                        valid = 0;
                        break;
                    }

                    char expected;
                    if (c == ')') expected = '(';
                    else if (c == ']') expected = '[';
                    else expected = '{';

                    if (stack[stack_top] != expected) {
                        valid = 0;
                        break;
                    }

                    stack_top--;
                    // 狀態保持為 OPERATOR
                } else {
                    valid = 0;
                }
            }
        }

        // 檢查最後的條件
        // 1. 所有括號必須匹配（stack 為空）
        // 2. 必須停在 OPERATOR 狀態
        if (valid && stack_top == -1 && state == OPERATOR) {
            printf("true ():%d []:%d {}:%d\n", paren_count, bracket_count, brace_count);
        } else {
            printf("false\n");
        }
    }

    return 0;
}
