
GCC	= gcc
GCCOPT	= -Wall $(GCCWOPT) $(GCCPROTOOPT)
GCCWOPT = -Wundef -Wempty-body -Wfloat-equal -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
#ALL# GCCWOPT = -Wundef -Wempty-body -Wfloat-equal -Wextra
GCCPROTOOPT = -Wmissing-prototypes -Wstrict-prototypes

COPT	= -g

SRCDIR	= ./
GETSRCS	= `echo $(SRCDIR)/test*.c`
SRCS	= $(GETSRCS)

LIBBASE	= linux_port_lib

EXES	= $(SRCS:.c=)

all : gcc

gcc : lib
	make -i SRCS="$(SRCS)" CC=$(GCC) COPT="$(COPT)" exes

lib :
	gcc -c $(LIBBASE).c
	ar r $(LIBBASE).a $(LIBBASE).o

exes : $(EXES)

.c :
	@ echo "##### compile: $<"
	$(CC) $(COPT) -o $@ $< $(LIBBASE).a 

clean : clean_lib
	make SRCS="$(SRCS)" clean_exes

clean_exes :
	rm -f $(EXES)

clean_lib :
	rm -f $(LIBBASE).a

