TARGET  := bin/Laser.exe# 可執行檔檔名
SRC_DIR := src# 原始碼目錄
OBJ_DIR := obj# 中間碼目錄
LIB_DIR := lib# 函式庫目錄
DEP_DIR := deps# 依賴檔案目錄
INC_DIR := include# 函式庫的標頭檔目錄
SRC_FILES :=$(subst \,/,$(subst $(shell cd)\,,$(shell dir *.cpp /B /S)))#取得 SRC_DIR 底下所有的 .cpp 檔
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))#取得 OBJ_DIR 底下所有的 .o 檔
DEP_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(DEP_DIR)/%.d,$(SRC_FILES))#取得 DEP_DIR 底下所有的 .o 檔

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

-include $(DEP_FILES)

$(TARGET):$(OBJ_FILES)# 將所有 .o Link 成 Laser.exe
	@$(CPP) $(CPPFLAGS) $(INCFLAGS) -o $@ $(OBJ_FILES) $(LFLAGS) $(SLFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp# 編譯 .d 檔
# 創建 obj 底下的目檔
	-@md $(subst /,\,$(@D))
# 創建 dep 底下的目錄
	-@md $(subst /,\,$(subst $(OBJ_DIR),$(DEP_DIR),$(@D)))
	$(CPP) $(CPPFLAGS) $(INCFLAGS) -c -MMD -MF $(DEP_DIR)/$*.d $< -o $@

clean:# 清除 obj 底下的所有東西
	@cd $(OBJ_DIR) && del /s *.o
	@cd $(DEP_DIR) && del /s *.d
	-@cd $(OBJ_DIR) && rmdir /s /q .
	-@cd $(DEP_DIR) && rmdir /s /q .

info:# 印出相關的參數資訊
	@echo ARGS="$(CPPFLAGS) $(INCFLAGS) $(LFLAGS) $(SLFLAGS)"
	@echo ===================================================
	@echo SRC_FILES="$(SRC_FILES)"
	@echo ===================================================
	@echo OBJ_FILES="$(OBJ_FILES)"
	@echo ===================================================
	@echo DEP_FILES="$(DEP_FILES)"