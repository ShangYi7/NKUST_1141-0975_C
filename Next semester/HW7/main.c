#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 協助函式: 從 token 中擷取符合題目定義的單字 (前後去標點，中間全為英文字母)
void extract_word(const char *token, char *core) {
    int len = strlen(token);
    int start = 0;
    int end = len - 1;

    // 移除前端標點符號
    while (start <= end && ispunct((unsigned char)token[start])) {
        start++;
    }
    // 移除後端標點符號
    while (end >= start && ispunct((unsigned char)token[end])) {
        end--;
    }

    if (start > end) {
        core[0] = '\0'; // 全是標點符號
        return;
    }

    // 複製中間的部分
    int core_idx = 0;
    for (int i = start; i <= end; i++) {
        core[core_idx++] = token[i];
    }
    core[core_idx] = '\0';

    // 檢查剩餘部分是否全為英文字母
    for (int i = 0; i < core_idx; i++) {
        if (!isalpha((unsigned char)core[i])) {
            core[0] = '\0';
            return;
        }
    }
}

int main() {
    int cmd;
    char current_string[10000] = "";

    // 持續讀取功能代號
    while (scanf("%d", &cmd) == 1) {
        if (cmd < 1 || cmd > 10) break;

        if (cmd == 1) {
            char input[10000];
            input[0] = '\0';

            // 跳過前置空白字元與換行
            int c;
            while ((c = getchar()) != EOF && isspace(c));
            if (c != EOF) {
                ungetc(c, stdin);
            }

            if (fgets(input, sizeof(input), stdin) != NULL) {
                // 移除尾端的換行字元
                input[strcspn(input, "\r\n")] = '\0';

                // 若目前文本已有內容，加入一個空白作為區隔
                if (strlen(current_string) > 0 && strlen(input) > 0) {
                    strcat(current_string, " ");
                }
                strcat(current_string, input);
            }
            printf("Current string=%s\n", current_string);
        }
        else if (cmd == 2) {
            // 強制轉型避免 warning
            printf("Total number of characters=%lu\n", (unsigned long)strlen(current_string));
        }
        else if (cmd == 3) {
            int count = 0;
            for (int i = 0; current_string[i] != '\0'; i++) {
                if (isalpha((unsigned char)current_string[i])) {
                    count++;
                }
            }
            printf("Number of English letters=%d\n", count);
        }
        else if (cmd == 4) {
            int tokens = 0;
            int i = 0;
            int len = strlen(current_string);

            while (i < len) {
                while (i < len && isspace((unsigned char)current_string[i])) i++;
                if (i == len) break;

                int end = i;
                while (end < len && !isspace((unsigned char)current_string[end])) end++;

                tokens++;
                i = end;
            }
            printf("Number of tokens=%d\n", tokens);
        }
        else if (cmd == 5) {
            int words = 0;
            int i = 0;
            int len = strlen(current_string);

            while (i < len) {
                while (i < len && isspace((unsigned char)current_string[i])) i++;
                if (i == len) break;

                int end = i;
                while (end < len && !isspace((unsigned char)current_string[end])) end++;

                char token[1000];
                int token_len = end - i;
                strncpy(token, &current_string[i], token_len);
                token[token_len] = '\0';

                char core[1000];
                extract_word(token, core);
                if (strlen(core) > 0) {
                    words++;
                }
                i = end;
            }
            printf("Number of words=%d\n", words);
        }
        else if (cmd == 6) {
            char keyword[1000];
            scanf("%s", keyword);

            int count = 0;
            int i = 0;
            int len = strlen(current_string);

            while (i < len) {
                while (i < len && isspace((unsigned char)current_string[i])) i++;
                if (i == len) break;

                int end = i;
                while (end < len && !isspace((unsigned char)current_string[end])) end++;

                char token[1000];
                int token_len = end - i;
                strncpy(token, &current_string[i], token_len);
                token[token_len] = '\0';

                char core[1000];
                extract_word(token, core);
                if (strcmp(core, keyword) == 0) {
                    count++;
                }
                i = end;
            }
            printf("Number of keywords=%d\n", count);
        }
        else if (cmd == 7) {
            char longest[1000] = "";
            int i = 0;
            int len = strlen(current_string);

            while (i < len) {
                while (i < len && isspace((unsigned char)current_string[i])) i++;
                if (i == len) break;

                int end = i;
                while (end < len && !isspace((unsigned char)current_string[end])) end++;

                char token[1000];
                int token_len = end - i;
                strncpy(token, &current_string[i], token_len);
                token[token_len] = '\0';

                char core[1000];
                extract_word(token, core);
                // > 確保長度相同時，保留最早遇到的
                if (strlen(core) > strlen(longest)) {
                    strcpy(longest, core);
                }
                i = end;
            }
            printf("Longest word=%s\n", longest);
        }
        else if (cmd == 8) {
            char keyword[1000];
            scanf("%s", keyword);

            int i = 0;
            while (current_string[i] != '\0') {
                int len = strlen(current_string);

                while (i < len && isspace((unsigned char)current_string[i])) i++;
                if (i == len) break;

                int end = i;
                while (end < len && !isspace((unsigned char)current_string[end])) end++;

                int w_start = i;
                int w_end = end - 1;
                while (w_start <= w_end && ispunct((unsigned char)current_string[w_start])) w_start++;
                while (w_end >= w_start && ispunct((unsigned char)current_string[w_end])) w_end--;

                if (w_start <= w_end) {
                    char core[1000];
                    int core_len = w_end - w_start + 1;
                    strncpy(core, &current_string[w_start], core_len);
                    core[core_len] = '\0';

                    int is_w = 1;
                    for (int j = 0; j < core_len; j++) {
                        if (!isalpha((unsigned char)core[j])) {
                            is_w = 0;
                            break;
                        }
                    }

                    if (is_w && strcmp(core, keyword) == 0) {
                        for (int j = w_start; j <= w_end; j++) {
                            current_string[j] = toupper((unsigned char)current_string[j]);
                        }
                    }
                }
                i = end;
            }
            printf("Current string=%s\n", current_string);
        }
        else if (cmd == 9) {
            char keyword[1000];
            scanf("%s", keyword);

            int i = 0;
            while (current_string[i] != '\0') {
                int len = strlen(current_string);

                while (i < len && isspace((unsigned char)current_string[i])) i++;
                if (i == len) break;

                int end = i;
                while (end < len && !isspace((unsigned char)current_string[end])) end++;

                int w_start = i;
                int w_end = end - 1;
                while (w_start <= w_end && ispunct((unsigned char)current_string[w_start])) w_start++;
                while (w_end >= w_start && ispunct((unsigned char)current_string[w_end])) w_end--;

                if (w_start <= w_end) {
                    char core[1000];
                    int core_len = w_end - w_start + 1;
                    strncpy(core, &current_string[w_start], core_len);
                    core[core_len] = '\0';

                    int is_w = 1;
                    for (int j = 0; j < core_len; j++) {
                        if (!isalpha((unsigned char)core[j])) {
                            is_w = 0;
                            break;
                        }
                    }

                    if (is_w && strcmp(core, keyword) == 0) {
                        // 使用 memmove 移除關鍵字，把後面的字串往前挪
                        memmove(&current_string[w_start], &current_string[w_start + core_len], len - (w_start + core_len) + 1);
                        end -= core_len; // 調整 end 指標
                    }
                }
                i = end;
            }
            printf("Current string=%s\n", current_string);
        }
        else if (cmd == 10) {
            int found = 0;
            int i = 0;
            while (current_string[i] != '\0') {
                int len = strlen(current_string);
                char c = current_string[i];

                int has_sign = (c == '-' || c == '+');
                int next_is_digit = (i + 1 < len && isdigit((unsigned char)current_string[i + 1]));

                if (isdigit((unsigned char)c) || (has_sign && next_is_digit)) {
                    int start = i;
                    if (has_sign) i++;

                    while (i < len && isdigit((unsigned char)current_string[i])) {
                        i++;
                    }

                    char num_str[1000];
                    int num_len = i - start;
                    strncpy(num_str, &current_string[start], num_len);
                    num_str[num_len] = '\0';

                    if (num_str[0] != '-' && num_str[0] != '+') {
                        printf("+%s\n", num_str);
                    } else {
                        printf("%s\n", num_str);
                    }
                    found = 1;
                } else {
                    i++;
                }
            }
            if (!found) printf("NONE\n");
        }
    }
    return 0;
}