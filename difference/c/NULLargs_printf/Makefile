
GCC	= gcc

GCCWOPT = -Wundef -Wempty-body -Wfloat-equal -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
#ALL# GCCWOPT = -Wundef -Wempty-body -Wfloat-equal -Wextra
GCCPROTOOPT = -Wmissing-prototypes -Wstrict-prototypes
GCCOPT	= -Wall $(GCCWOPT) $(GCCPROTOOPT)

COPT	= -g $(GCCOPT)

SRCDIR	= ./
GETSRCS	= `echo $(SRCDIR)/*.c`
SRCS	= $(GETSRCS)


EXES	= $(SRCS:.c=)

all : gcc

gcc :
	make -i SRCS="$(SRCS)" CC=$(GCC) COPT="$(COPT)" exes

exes : $(EXES)

.c :
	@ echo "##### compile: $<"
	$(CC) $(COPT) -o $@ $<

clean :
	make SRCS="$(SRCS)" clean_exes

clean_exes :
	rm -f $(EXES)

