TARGET	= mabel
MODULES = lex

############### Make ###############
CC=gcc
CFLAGS=-Iinclude -Wall -std=c99 -g

SRC_DIR := $(addprefix src/,$(MODULES)) src
OBJ_DIR = obj

SRCS=$(foreach srcdir,$(SRC_DIR),$(wildcard $(srcdir)/*.c))
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean