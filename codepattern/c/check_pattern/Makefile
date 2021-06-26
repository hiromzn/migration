#

SILENT_FLAG = .SILENT
#$(SILENT_FLAG) :

# source directory
SRC = src

# bin directory
BIN = bin

CC = gcc

CFLAGS = -g -Wall

srcs = $(wildcard $(SRC)/*.c)

tgt = $(patsubst $(SRC)/%,$(BIN)/%,$(srcs:.c=))

all : mkenv $(tgt)

mkenv:
	-mkdir -p $(BIN)

$(tgt): $(srcs)
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f $(tgt) *~ 
	rm -rf $(BIN)/*.dSYM

