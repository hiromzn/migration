srcs = $(wildcard *.c)

objs = $(srcs:.c=.o)

base = $(srcs:.c=)

tgt = run

osym = $(base:=.sym)

xsym = $(tgt).sym

all : $(tgt) ana

$(tgt): $(objs)
	$(CC) $(CFLAGS) $(objs) -o $@

#$(base): %.c
#OK# $(objs): %.o: %.c
#WAN# $(base): %.o: %.c
#NG# $(objs): %.c
#.o.c :
$(objs): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(tgt) $(objs) $(osym) $(xsym)


ana : symbol

symbol: $(osym) $(xsym)

$(osym): %.sym: %.o
	LANG=C objdump -t $< >$@

$(xsym): %.sym: %
	LANG=C objdump -t $< >$@
