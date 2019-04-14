
CC	= cc
COPT	=

CA	= cadvise
#CA	= /opt/cadvise/bin/cadvise
CAOPT	= -pdb $(PDB) +wall cc +DD64 +w

GCC	= gcc
GCCOPT	= -Wall $(GCCWOPT) $(GCCPROTOOPT)
GCCWOPT = -Wundef -Wempty-body -Wfloat-equal -Wextra -Wno-unused-parameter -Wno-missing-field-initializers
GCCPROTOOPT = -Wmissing-prototypes -Wstrict-prototypes

SRCDIR	= ./src
GETSRCS = `echo $(SRCDIR)/ca-*.c`
GETPROTOSRCS = `echo $(SRCDIR)/proto-*.c`
ALLSRCS = $(GETSRCS) $(GETPROTOSRCS)

OBJS	= $(SRCS:.c=.o)

LOGDIR	= ./log

# CodeAdvisor
PDB = ./pdb

all :
	make setup;
	make getinfo;
	if [ "`uname -s`" = "Linux" ]; then \
		( \
		make getinfo; \
		make gcc; \
		) 2>&1 |tee $(LOGDIR)/makeall-gcc.log; \
	else \
		( \
		make getinfo; \
		make ca; \
		) 2>&1 |tee $(LOGDIR)/makeall-ca.log; \
	fi;

ca :
	make setup
	make SRCS="$(GETSRCS)" CC=$(CA) COPT="$(CAOPT) $(COPT)" objs

gcc :
	make setup
	make SRCS="$(GETSRCS)" CC=$(GCC) COPT="$(GCCOPT) $(COPT)" objs

proto :
	make setup
	make SRCS="$(GETPROTOSRCS)" CC=$(GCC) COPT="$(GCCOPT) $(GCCPROTOOPT) $(COPT)" objs

objs : $(OBJS)

setup :
	@ if [ ! -d $(LOGDIR) ]; then mkdir $(LOGDIR); fi

getinfo :
	LANG=C date;
	hostname;
	uname -a;
	- $(CC) -v

debug :
	make SRCS="$(GETSRCS)" debug-body

debug-body :
	echo "$(SRCDIR)"
	echo "$(SRCS)"
	echo "$(OBJS)"
	echo "$(TGT)"

.c.o :
	@ echo "##### compile $<"
	- $(CC) $(COPT) -c -o $@ $<

clean :
	make SRCS="$(ALLSRCS)" cleans

cleans :
	rm -rf $(PDB)
	rm -f $(OBJS)

