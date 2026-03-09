# RACKlette Recruiting Task -- Makefile

CC     = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
TARGET = task
SRC    = task.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
	@echo "Build successful! Run with:  ./task"

clean:
	rm -f $(TARGET)
