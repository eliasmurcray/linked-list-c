CC = gcc
CFLAGS = -std=c89 -Wall -Wextra
SRC_FILES = $(wildcard src/*.c)
BUILD_DIR = build
OBJ_NAME = main

all:
	$(CC) $(CFLAGS) -O0 -g -Iinclude $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
