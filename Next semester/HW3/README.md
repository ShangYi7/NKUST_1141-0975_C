# 計算機程式設計 HW03

## 題目目標

開發「會員管理模組」並整合到主程式流程，依照模組代號與功能代號執行對應行為。

## 作業規定整理

### 1. 主模組流程

- 可持續輸入模組代號。
- 模組代號 `1`：進入會員管理模組，輸出 `Use member function`。
- 模組代號 `-1`：結束程式，輸出 `Goodbye`。
- 其他模組代號：輸出 `No such command`。

### 2. 會員管理模組流程

- 進入後可持續輸入功能代號。
- 功能代號對應如下：
  - `1` 新增會員：輸入 `會員ID 姓名 電話 地址`
  - `2` 修改會員：輸入 `會員ID 欄位編號 新資料`
  - `3` 刪除會員：輸入 `會員ID`
  - `4` 查詢會員：輸入 `會員ID`
  - `5` 查詢全部會員：依 ID 由小到大輸出
- 若功能代號不是 `1~5`：退出會員管理模組，輸出 `Exit member function`。

### 3. 各功能輸出規則

- 新增：
  - ID 重複 -> `ID duplicated`
  - 新增成功 -> `Creation successful`
- 修改：
  - ID 不存在 -> `No such ID`
  - 修改成功 -> 輸出 `會員ID 姓名 電話 地址`
- 刪除：
  - ID 不存在 -> `No such ID`
  - 刪除成功 -> `Deletion successful`
- 查詢單筆：
  - ID 不存在 -> `No such ID`
  - 查詢成功 -> 輸出 `會員ID 姓名 電話 地址`
- 查詢全部：
  - 依 ID 由小到大，每行輸出 `會員ID 姓名 電話 地址`

### 4. 欄位規格

- 會員ID：整數（輸入為正整數）
- 姓名：10 字元（無空白）
- 電話：10 字元（無空白）
- 地址：50 字元（無空白）
- 新增會員總數不超過 100

## 專案檔案

- `main.c`：主程式
- `input.txt`：測試輸入範例
- `expected_output.txt`：預期輸出範例

## 測試方式

### 1. 編譯

```bash
gcc main.c -o main.exe
```

### 2. 依 input.txt 執行

```bash
cmd /c "main.exe < input.txt"
```

### 3.（建議）輸出比對

可先把實際輸出導到檔案，再和預期輸出比對：

```bash
cmd /c "main.exe < input.txt > actual_output.txt"
```

Windows 內建比對（CMD）：

```bash
cmd /c "fc actual_output.txt expected_output.txt"
```

成功訊息（代表輸出一致）：

```text
Comparing files actual_output.txt and EXPECTED_OUTPUT.TXT
FC: no differences encountered
```

PowerShell 比對（顯示差異物件）：

```powershell
Compare-Object (Get-Content expected_output.txt) (Get-Content actual_output.txt)
```

## 注意事項

- 評測通常會比對字串，請注意大小寫、空白與換行。
- 若使用測資檔測試卻沒輸出，請確認 `input.txt` 編碼為一般文字（建議 UTF-8 或 ASCII）。
