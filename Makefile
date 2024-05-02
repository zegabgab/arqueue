CC = gcc
SRC = src
TARGET = target
OBJ = target/obj
BINDIR = target/bin
BIN = test
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c))

all: dirs main

clean:
	rm -rf $(TARGET)

dirs: $(TARGET)/ $(OBJ)/ $(BINDIR)/

%/:
	mkdir $@

main: $(BINDIR)/$(BIN)

$(BINDIR)/$(BIN): $(OBJS)
	$(CC) -o $@ $(OBJ)/*.o

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -o $@ -c $?
