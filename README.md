# 開發說明

請確認你的電腦已安裝

### [Git](https://git-scm.com/downloads)

### [MinGW-W64](https://sourceforge.net/projects/mingw-w64/)
* 版本version: 8.1.0 <br>
* 架構architecture: x86_64

## 下載原始碼

複製完整的內容:
```bash
git clone https://github.com/xLanStar/Laser.git
cd Laser
git branch develop origin/develop
```

更新本機的原始碼
```bash
git pull
```

上傳本機的所有修改內容
```bash
git push
```

更新遠端的 master 為當前遠端的 develop 版本
```bash
git checkout develop
git pull
git checkout master
git pull
git merge develop
git push -u origin master
```

## 環境設定

* C++標準涵式庫: C++11
* 編譯器路徑: `MinGW路徑\bin\g++.exe`
* 涵式庫路徑: 
    * `MinGW路徑\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++` C++標準涵式庫
    * `${workspaceFolder}/include` 專案引入之標頭黨
    * `${workspaceFolder}/src` 此專案之原始碼


## 相關規範

### 檔案架構
* `bin/` 已編譯之應用程式
* `include/` 引入之標頭檔，原始碼會從這裡找函數方法
* `lib/` 引入之靜態連結函式庫，編譯器會從這裡連結函數
* `src/` 此專案之原始碼，包含標頭檔以及c++檔案

### 原始碼規範
* 引入系統標頭檔使用`include <>`
* 引入專案標頭檔使用`include ""`
* `C++檔案`、`Class物件` 應以大寫為開頭命名
* `Function函數`、`Variable變數` 應以小寫為開頭命名
* `Const常數` 應以全大寫命名

