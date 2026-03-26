// 圖書借閱系統
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 會員結構定義
typedef struct
{
    char name[50];
    char phone[20];
    char address[100];
} Member;

// 全局變數
Member members[101];
int is_used[100] = {0}; // 0 = 沒資料, 1 = 有資料
int member_count = 0;
int mode; // 主模組模式選擇

// 函數聲明
void member_management(); // 會員管理主模組
void add_member();        // 新增
void edit_member();       // 修改
void delete_member();     // 刪除
void query_member();      // 查詢單一會員
void query_all_members(); // 查詢所有會員

int main()
{
    while (scanf("%d", &mode) != EOF && mode != -1)
    {
        switch (mode)
        {
            case 1:
                printf("Use member function\n");
                member_management();
                break;

            default:
                // TODO: 尚未開發
                break;
        }
    }
    system("pause");
    return 0;
}

void member_management()
{
    // 會員管理模組
    int manage_mode; // 管理模組選擇
    while (scanf("%d", &manage_mode) <= 5)
    {
        switch (manage_mode)
        {
            case 1:
                // 新增會員資料
                add_member();
                break;
            case 2:
                // 修改指定會員資料
                edit_member();

                break;
            case 3:
                // 刪除一筆會員資料
                delete_member();

                break;
            case 4:
                // 查詢一筆會員資料
                query_member();

                break;
            case 5:
                // 查詢所有會員資料
                query_all_members();
                break;
        }
    }
    return;
}

// 新增
void add_member()
{
    int id;
    char name[50], phone[20], address[100];
    scanf("%d %49s %19s %99s", &id, name, phone, address);
    if (is_used[id] == 0)
    {
        strcpy(members[id].name, name);
        strcpy(members[id].phone, phone);
        strcpy(members[id].address, address);
        is_used[id] = 1;
        printf("Creation successful\n");
    }
    else
    {
        printf("ID duplicated\n");
    }
    return;
    // printf("%d %s %s %s %d\n", id, members[id].name, members[id].phone, members[id].address,
    // is_used[id]);
}

// 修改
void edit_member()
{
    int id;
    int label_id; // 1=姓名, 2=電話, 3=地址
    char name[50], phone[20], address[100];
    scanf("%d %d", &id, &label_id);
    if (is_used[id] == 0)
    {
        printf("No such ID\n");
        return;
    }
    else
    {
        switch (label_id)
        {
            case 1:
                scanf("%49s", name);
                strcpy(members[id].name, name);
                break;
            case 2:
                scanf("%19s", phone);
                strcpy(members[id].phone, phone);
                break;
            case 3:
                scanf("%99s", address);
                strcpy(members[id].address, address);
                break;
        }
        printf("%d %s %s %s\n", id, members[id].name, members[id].phone, members[id].address);
    }
    return;
}

// 刪除
void delete_member()
{
    int id;
    scanf("%d", &id);
    if (is_used[id] == 0)
    {
        printf("No such ID\n");
    }
    else
    {
        is_used[id] = 0;
        printf("Deletion successful\n");
    }
    return;
}

// 查詢單一會員
void query_member()
{
    int id;
    scanf("%d", &id);
    if (is_used[id] == 0)
    {
        printf("No such ID\n");
    }
    else
    {
        printf("%d %s %s %s\n", id, members[id].name, members[id].phone, members[id].address);
    }
    return;
}

// 查詢所有會員
void query_all_members()
{
    for (size_t id = 0; id < 100; id++)
    {
        if (is_used[id] == 1)
        {
            printf("%d %s %s %s\n", id, members[id].name, members[id].phone, members[id].address);
        }
    }
    return;
}
