
srcs = $(wildcard *.c)

tgt = $(srcs:.c=)

all : $(tgt)

$(tgt): %: %.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f $(tgt) *~
