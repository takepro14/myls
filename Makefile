CC = gcc
CFLAGS = -std=c17 -Wall -Wextra
TARGET = bin/myls
SRC = src/myls.c src/main.c

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -rf bin
