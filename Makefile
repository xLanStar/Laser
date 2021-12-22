SRC_DIR := src# 原始碼目錄
OBJ_DIR := obj# 中間碼目錄
LIB_DIR := lib# 函式庫目錄
INC_DIR := include# 函式庫的標頭檔目錄
TARGET  := bin/Laser.exe# 可執行檔檔名
SRC_FILES :=$(filter-out $(SRC_DIR)/main.cpp,$(subst \,/,$(subst $(shell cd)\,,$(shell dir *.cpp /B /S))))#取得 SRC_DIR 底下所有的 .cpp 檔
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))#取得 OBJ_DIR 底下所有的 .o 檔
# Compiler
CPP:=g++
# 參數
CPPFLAGS :=-g -O3 -Wno-deprecated
INCFLAGS = -I$(INC_DIR) -I$(SRC_DIR)
LFLAGS := -lsfml-graphics -lsfml-window -lsfml-system
SLFLAGS = -L$(LIB_DIR)

.PHONY : all clean info

all:$(TARGET)# 預設進入點
	@echo "compile finish"

$(TARGET):$(SRC_DIR)/main.cpp $(OBJ_FILES)# 將所有 .o Link 成 Laser.exe
	@$(CPP) $(CPPFLAGS) $(INCFLAGS) $< -o $@ $(OBJ_FILES) $(LFLAGS) $(SLFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp# 編譯成 .o 檔
	-@md $(subst /,\,$(@D))
	$(CPP) $(CPPFLAGS) $(INCFLAGS) -c -o $@ $<

clean:# 清除 obj 底下的所有東西
	@cd obj && del /s *.o
	@cd obj && rmdir /s /q .

info:# 印出相關的參數資訊
	@echo "$(SRC_FILES)"
	@echo "$(OBJ_FILES)"