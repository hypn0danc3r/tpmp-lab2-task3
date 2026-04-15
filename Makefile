# Makefile для проекта tpmp-lab2-task3
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/task3.c
OBJ = $(SRC:.c=.o)
TARGET = bin/lab2-task3

all: $(TARGET)

$(TARGET): $(OBJ) | bin
	$(CC) $(OBJ) -o $(TARGET) -lm

bin:
	mkdir -p bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

check:
	@echo "Check target"

distcheck:
	@echo "Distcheck target"

.PHONY: all clean check distcheck