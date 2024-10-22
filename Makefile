NAME = hangman

# Compiler
CC = gcc

# Flags
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Iinclude

# Intallation directory
PREFIX = /usr/local

# Binaries
BINDIR = $(PREFIX)/bin

# Directory ofr object files
BUILD_DIR = build

# Targets
all: $(NAME)

$(NAME): $(BUILD_DIR)/main.o $(BUILD_DIR)/hangman.o $(BUILD_DIR)/menu.o
	$(CC) $(CFLAGS) -o $(NAME) $(BUILD_DIR)/main.o $(BUILD_DIR)/hangman.o $(BUILD_DIR)/menu.o

$(BUILD_DIR)/main.o: src/main.c include/hangman.h include/menu.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c src/main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/hangman.o: src/hangman.c include/hangman.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c src/hangman.c -o $(BUILD_DIR)/hangman.o

$(BUILD_DIR)/menu.o: src/menu.c include/menu.h
	$(CC) $(CFLAGS) -c src/menu.c -o $(BUILD_DIR)/menu.o

install: $(NAME)
	sudo install -m 755 $(NAME) $(BINDIR)

uninstall:
	sudo rm -f $(BINDIR)/$(NAME)

clean:
	rm -f $(NAME) $(BUILD_DIR)/*.o
