root_dir := $(shell pwd)

SRC_DIR := $(root_dir)/src
INC_DIR := $(root_dir)/inc
OBJ_DIR := $(root_dir)/obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

CC := gcc
CFLAGS := -c -Wall -Ofast -std=gnu99
LFLAGS := -Wall -fuse-ld=gold -std=gnu99 -static

$(OBJ_DIR)/photorg: $(OBJ_FILES)
	$(CC) $(LFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $<

docs: $(OBJ_DIR)/photorg
	doxygen Doxyfile

clean:
	rm $(OBJ_DIR)/*
