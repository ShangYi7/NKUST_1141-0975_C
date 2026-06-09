#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// 協助函式: 從 token 中擷取符合題目定義的單字 (前後去標點，中間全為英文字母)
string extract_word(string token) {
    int start = 0;
    // 移除前端標點符號
    while(start < token.length() && ispunct(token[start])) {
        start++;
    }
    int end = token.length() - 1;
    // 移除後端標點符號
    while(end >= start && ispunct(token[end])) {
        end--;
    }

    if(start > end) return ""; // 全是標點符號

    string core = token.substr(start, end - start + 1);
    // 檢查剩餘部分是否全為英文字母
    for(char c : core) {
        if(!isalpha(c)) return "";
    }
    return core;
}

int main() {
    int cmd;
    string current_string = "";

    // 持續讀取功能代號
    while (cin >> cmd) {
        if (cmd < 1 || cmd > 10) break; // 輸入非 1~10 代號則結束程式

        if (cmd == 1) {
            string input;
            cin >> ws; // 忽略前面的空白字元與換行
            getline(cin, input);
            // 若目前文本已有內容，加入一個空白作為區隔
            if (!current_string.empty()) current_string += " ";
            current_string += input;
            cout << "Current string=" << current_string << "\n";
        }
        else if (cmd == 2) {
            cout << "Total number of characters=" << current_string.length() << "\n";
        }
        else if (cmd == 3) {
            int count = 0;
            for (char c : current_string) {
                if (isalpha(c)) count++;
            }
            cout << "Number of English letters=" << count << "\n";
        }
        else if (cmd == 4) {
            int tokens = 0;
            size_t start = 0;
            while (start < current_string.length()) {
                while (start < current_string.length() && isspace(current_string[start])) start++;
                if (start == current_string.length()) break;
                size_t end = start;
                while (end < current_string.length() && !isspace(current_string[end])) end++;
                tokens++;
                start = end;
            }
            cout << "Number of tokens=" << tokens << "\n";
        }
        else if (cmd == 5) {
            int words = 0;
            size_t start = 0;
            while (start < current_string.length()) {
                while (start < current_string.length() && isspace(current_string[start])) start++;
                if (start == current_string.length()) break;
                size_t end = start;
                while (end < current_string.length() && !isspace(current_string[end])) end++;

                string token = current_string.substr(start, end - start);
                if (!extract_word(token).empty()) words++;

                start = end;
            }
            cout << "Number of words=" << words << "\n";
        }
        else if (cmd == 6) {
            string keyword;
            cin >> keyword;
            int count = 0;
            size_t start = 0;
            while (start < current_string.length()) {
                while (start < current_string.length() && isspace(current_string[start])) start++;
                if (start == current_string.length()) break;
                size_t end = start;
                while (end < current_string.length() && !isspace(current_string[end])) end++;

                string token = current_string.substr(start, end - start);
                if (extract_word(token) == keyword) count++;

                start = end;
            }
            cout << "Number of keywords=" << count << "\n";
        }
        else if (cmd == 7) {
            string longest = "";
            size_t start = 0;
            while (start < current_string.length()) {
                while (start < current_string.length() && isspace(current_string[start])) start++;
                if (start == current_string.length()) break;
                size_t end = start;
                while (end < current_string.length() && !isspace(current_string[end])) end++;

                string token = current_string.substr(start, end - start);
                string w = extract_word(token);
                // 使用 > 確保若長度相同，保留最早遇到的單字
                if (!w.empty() && w.length() > longest.length()) {
                    longest = w;
                }

                start = end;
            }
            cout << "Longest word=" << longest << "\n";
        }
        else if (cmd == 8) {
            string keyword;
            cin >> keyword;
            size_t start = 0;
            while (start < current_string.length()) {
                while (start < current_string.length() && isspace(current_string[start])) start++;
                if (start == current_string.length()) break;
                size_t end = start;
                while (end < current_string.length() && !isspace(current_string[end])) end++;

                string token = current_string.substr(start, end - start);

                int w_start = 0, w_end = token.length() - 1;
                while (w_start <= w_end && ispunct(token[w_start])) w_start++;
                while (w_end >= w_start && ispunct(token[w_end])) w_end--;

                if (w_start <= w_end) {
                    string core = token.substr(w_start, w_end - w_start + 1);
                    bool is_w = true;
                    for (char c : core) if (!isalpha(c)) is_w = false;

                    // 若找到相符的關鍵字，將文本中對應的位置轉大寫
                    if (is_w && core == keyword) {
                        for (int j = 0; j < core.length(); j++) {
                            current_string[start + w_start + j] = toupper(current_string[start + w_start + j]);
                        }
                    }
                }
                start = end;
            }
            cout << "Current string=" << current_string << "\n";
        }
        else if (cmd == 9) {
            string keyword;
            cin >> keyword;
            size_t start = 0;
            while (start < current_string.length()) {
                while (start < current_string.length() && isspace(current_string[start])) start++;
                if (start == current_string.length()) break;
                size_t end = start;
                while (end < current_string.length() && !isspace(current_string[end])) end++;

                string token = current_string.substr(start, end - start);

                int w_start = 0, w_end = token.length() - 1;
                while (w_start <= w_end && ispunct(token[w_start])) w_start++;
                while (w_end >= w_start && ispunct(token[w_end])) w_end--;

                if (w_start <= w_end) {
                    string core = token.substr(w_start, w_end - w_start + 1);
                    bool is_w = true;
                    for (char c : core) if (!isalpha(c)) is_w = false;

                    // 若找到相符的關鍵字，直接從原字串中抹除該單字核心，保留原有的空白與標點
                    if (is_w && core == keyword) {
                        current_string.erase(start + w_start, core.length());
                        end -= core.length(); // 因為字串縮短了，調整 end 指標
                    }
                }
                start = end;
            }
            cout << "Current string=" << current_string << "\n";
        }
        else if (cmd == 10) {
            bool found = false;
            for (size_t i = 0; i < current_string.length(); ) {
                // 判斷是否為數字開頭 (直接是數字，或是正負號後面緊接數字)
                if (isdigit(current_string[i]) || ( (current_string[i] == '-' || current_string[i] == '+') && i + 1 < current_string.length() && isdigit(current_string[i+1]) )) {
                    int start = i;
                    if (current_string[i] == '-' || current_string[i] == '+') i++;
                    while (i < current_string.length() && isdigit(current_string[i])) i++;

                    string num_str = current_string.substr(start, i - start);
                    // 根據是否有自帶符號來決定是否補上 '+'
                    if (num_str[0] != '-' && num_str[0] != '+') {
                        cout << "+" << num_str << "\n";
                    } else {
                        cout << num_str << "\n";
                    }
                    found = true;
                } else {
                    i++;
                }
            }
            if (!found) cout << "NONE\n";
        }
    }
    return 0;
}