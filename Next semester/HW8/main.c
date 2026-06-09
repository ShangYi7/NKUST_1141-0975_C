// 圖書借閱系統
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 會員結構定義
typedef struct
{
    char name[11];
    char phone[11];
    char address[51];
} Member;

// 全局變數
Member members[100];
int is_used[100] = {0}; // 0 == 沒資料, 1 == 有資料
int member_count = 0;
int mode; // 主模組模式選擇

// 借閱結構定義
typedef struct{
    char BookId[20];
    char BookName[20];
    int BookStatus; //0 == 已借出 ,1 == 未借出
    int  Borrower_id; // 誰借閱
}Book;

Book books[20];
// 書籍ID
const char* BookId[20]={"B01","B02","B03","B04","B05","B06","B07","B08","B09","B10",
"B001","B002","B003","B004","B005","B006","B007","B008","B009","B010"};

// 書籍名稱
const char* BookName[20]={"CPrimer","VerilogX","LogicLab","FPGAPro","BitFlow","CircuitX","DataBus","RegMap","SignalIQ","WaveCore",
"CMOSArt","SyncEdge","ByteCode","StackMem","AXIWorld","BusLogic","ICDesign","NetClock","EmbedSys","WireLink"};

int is_valid_id(int id)
{
    return id >= 0 && id < 100;
}

int is_valid_book_id(const char* book_id)
{
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(BookId[i], book_id) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int find_book_index(const char* book_id)
{
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(BookId[i], book_id) == 0)
        {
            return i;
        }
    }
    return -1;
}

// 函數聲明

// 借閱管理
void borrow_management();         // 借閱管理主模組
void borrow_lend_book();          // 借閱書籍
void borrow_return_book();        // 歸還書籍
void borrow_query_member_list();  // 查詢會員借閱清單
void borrow_query_book_details(); // 查詢單一書籍資訊
void borrow_list_all_books();     // 查詢所有書籍資訊

// 會員管理
void member_management();  // 會員管理主模組
void member_add();         // 新增
void member_edit();        // 修改
void member_delete();      // 刪除
void member_query();       // 查詢單一會員
void member_query_all();   // 查詢所有會員

int main()
{
    // 初始化書籍資料
    for (int i = 0; i < 20; i++)
    {
        books[i].BookStatus = 1;   // 1 == 未借出
        books[i].Borrower_id = -1; // -1 代表無人借閱
        strcpy(books[i].BookId, BookId[i]);
        strcpy(books[i].BookName, BookName[i]);
    }

    while (scanf("%d", &mode) == 1)
    {
        if (mode == -1)
        {
            printf("Goodbye\n");
            return 0;
        }

        switch (mode)
        {
            case 1:
                // 會員管理模組
                printf("Use member function\n");
                member_management();
                break;
            case 2:
                // 借閱管理模組
                printf("Use borrow function\n");
                borrow_management();
                break;
            default:
                // TODO: 尚未開發
                printf("No such command\n");
                break;
        }
    }

    return 0;
}

// 借閱管理模組
void borrow_management(){
    int manage_mode; // 管理模組選擇
    while (scanf("%d", &manage_mode) == 1)
    {
        if (manage_mode < 1 || manage_mode > 5)
        {
            printf("Exit borrow function\n");
            return;
        }

        switch (manage_mode)
        {
            case 1:
                // 借閱書籍
                borrow_lend_book();
                break;
            case 2:
                // 歸還書籍
                borrow_return_book();
                break;
            case 3:
                // 查詢會員借閱清單
                borrow_query_member_list();
                break;
            case 4:
                // 查詢單一書籍資訊
                borrow_query_book_details();
                break;
            case 5:
                // 查詢所有書籍資訊
                borrow_list_all_books();
                break;
        }
    }

    return;
}

// 會員管理模組
void member_management()
{
    int manage_mode; // 管理模組選擇
    while (scanf("%d", &manage_mode) == 1)
    {
        if (manage_mode < 1 || manage_mode > 5)
        {
            printf("Exit member function\n");
            return;
        }

        switch (manage_mode)
        {
            case 1:
                // 新增會員資料
                member_add();
                break;
            case 2:
                // 修改指定會員資料
                member_edit();

                break;
            case 3:
                // 刪除一筆會員資料
                member_delete();

                break;
            case 4:
                // 查詢一筆會員資料
                member_query();

                break;
            case 5:
                // 查詢所有會員資料
                member_query_all();
                break;
        }
    }

    return;
}

// 新增
void member_add()
{
    int id;
    char name[11], phone[11], address[51];
    scanf("%d %10s %10s %50s", &id, name, phone, address);
    if (is_valid_id(id) && is_used[id] == 0 && member_count < 100)
    {
        strcpy(members[id].name, name);
        strcpy(members[id].phone, phone);
        strcpy(members[id].address, address);
        is_used[id] = 1;
        member_count += 1;
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
void member_edit()
{
    int id;
    int label_id; // 1=姓名, 2=電話, 3=地址
    char new_data[51];
    scanf("%d %d %50s", &id, &label_id, new_data);
    if (!is_valid_id(id) || is_used[id] == 0)
    {
        printf("No such ID\n");
        return;
    }
    else
    {
        switch (label_id)
        {
            case 1:
                strncpy(members[id].name, new_data, 10);
                members[id].name[10] = '\0';
                break;
            case 2:
                strncpy(members[id].phone, new_data, 10);
                members[id].phone[10] = '\0';
                break;
            case 3:
                strncpy(members[id].address, new_data, 50);
                members[id].address[50] = '\0';
                break;
        }
        printf("%d %s %s %s\n", id, members[id].name, members[id].phone, members[id].address);
    }
    return;
}

// 刪除
void member_delete()
{
    int id;
    scanf("%d", &id);
    if (!is_valid_id(id) || is_used[id] == 0)
    {
        printf("No such ID\n");
    }
    else
    {
        is_used[id] = 0;
        member_count -= 1;
        printf("Deletion successful\n");
    }
    return;
}

// 查詢單一會員
void member_query()
{
    int id;
    scanf("%d", &id);
    if (!is_valid_id(id) || is_used[id] == 0)
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
void member_query_all()
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

// 借閱書籍
void borrow_lend_book()
{
    char book_id[20];
    int member_id;
    scanf("%s %d", book_id, &member_id);
    int book_index = find_book_index(book_id);
    if(book_index == -1)
    {
        printf("No such book ID\n");
        return;
    }
    if(!is_valid_id(member_id) || is_used[member_id] == 0)
    {
        printf("No such member ID\n");
        return;
    }
    if(books[book_index].BookStatus == 0)
    {
        int borrower_id = books[book_index].Borrower_id;
        printf("Not returned yet,%s is borrowed by %d_%s\n",
            BookId[book_index], borrower_id, members[borrower_id].name);
        return;
    }
    books[book_index].BookStatus = 0;
    books[book_index].Borrower_id = member_id;
    printf("%s is borrowed by %d_%s\n", BookId[book_index], member_id, members[member_id].name);
    return;
}

// 歸還書籍
void borrow_return_book()
{
    char book_id[20];
    scanf("%s", book_id);
    if(!is_valid_book_id(book_id))
    {
        printf("No such book ID\n");
        return;
    }
    int book_index = find_book_index(book_id);
    if(books[book_index].BookStatus == 1)
    {
        printf("No such transaction\n");
        return;
    }
    int borrower_id = books[book_index].Borrower_id;
    books[book_index].BookStatus = 1;
    books[book_index].Borrower_id = -1; // 重設借閱者ID
    printf("%s is returned by %d_%s\n", BookId[book_index], borrower_id, members[borrower_id].name);
    return;
}

// 查詢會員借閱清單
void borrow_query_member_list()
{
    int member_id;
    scanf("%d", &member_id);
    if (!is_valid_id(member_id) || is_used[member_id] == 0)
    {
        printf("No such member ID\n");
        return;
    }
    printf("%d %s\n", member_id, members[member_id].name);

    int has_borrowed = 0;
    for (int i = 0; i < 20; i++)
    {
        if (books[i].BookStatus == 0 && books[i].Borrower_id == member_id)
        {
            printf("%s %s\n", BookId[i], BookName[i]);
            has_borrowed = 1;
        }
    }
    if (!has_borrowed)
    {
        printf("None\n");
    }
    return;
}

// 查詢單一書籍資訊
void borrow_query_book_details()
{
    char book_id[20];
    scanf("%s", book_id);
    if (!is_valid_book_id(book_id))
    {
        printf("No such book ID\n");
        return;
    }
    int book_index = find_book_index(book_id);
    if (books[book_index].BookStatus == 0)
    {
        int borrower_id = books[book_index].Borrower_id;
        printf("%s %s (%d_%s)\n", BookId[book_index], BookName[book_index],
               borrower_id, members[borrower_id].name);
    }
    else
    {
        printf("%s %s\n", BookId[book_index], BookName[book_index]);
    }
    return;
}

// 查詢所有書籍資訊
void borrow_list_all_books()
{
    for (int i = 0; i < 20; i++)
    {
        if (books[i].BookStatus == 0)
        {
            int borrower_id = books[i].Borrower_id;
            printf("%s %s (%d_%s)\n", BookId[i], BookName[i],
                   borrower_id, members[borrower_id].name);
        }
        else
        {
            printf("%s %s\n", BookId[i], BookName[i]);
        }
    }
    return;
}
