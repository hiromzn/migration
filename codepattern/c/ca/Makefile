
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
MAKELOG = $(LOGDIR)/makeall.log
SUMMARYLOG = $(LOGDIR)/makesummary.log

# CodeAdvisor
PDB = ./pdb

all :
	make setup;
	-@case "`uname -s`" in \
	"Linux" | "Darwin") \
		( \
		make getinfo; \
		make gcc; \
		) 2>&1 |tee $(MAKELOG); \
		make summary; \
		;; \
	"HP-UX" ) \
		( \
		make getinfo; \
		make ca; \
		) 2>&1 |tee $(MAKELOG); \
		make summary; \
		;; \
	* ) \
		echo "ERROR: unknown OS : `uname -s`"; >&2 \
		;; \
	esac;

ca :
	make setup
	make SRCS="$(ALLSRCS)" CC=$(CA) COPT="$(CAOPT) $(COPT)" objs

gcc :
	make setup
	make SRCS="$(ALLSRCS)" CC=$(GCC) COPT="$(GCCOPT) $(GCCPROTOOPT) $(COPT)" objs

proto :
	make setup
	make SRCS="$(GETPROTOSRCS)" CC=$(GCC) COPT="$(GCCOPT) $(GCCPROTOOPT) $(COPT)" objs

objs : $(OBJS)

setup :
	@ if [ ! -d $(LOGDIR) ]; then mkdir $(LOGDIR); fi
	@ cp /dev/null $(SUMMARYLOG)

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
	@ echo "##### compile: $<"
	@ echo "##### command: $(CC) $(COPT) -c -o $@ $<" >$(LOGDIR)/$(*F).cmd
	-@ $(CC) $(COPT) -c -o $@ $< >$(LOGDIR)/$(*F).stdout 2>$(LOGDIR)/$(*F).stderr
	@ cat $(LOGDIR)/$(*F).cmd
	@ cat $(LOGDIR)/$(*F).stdout
	@ cat $(LOGDIR)/$(*F).stderr
	@ echo "$(*F):stdout=`stat --format=%s $(LOGDIR)/$(*F).stdout`:stderr=`stat --format=%s $(LOGDIR)/$(*F).stderr`" >>$(SUMMARYLOG)

summary :
	@( for f in 

clean :
	make SRCS="$(ALLSRCS)" cleans
	@ rm -f $(LOGDIR)/*.cmd
	@ rm -f $(LOGDIR)/*.stdout
	@ rm -f $(LOGDIR)/*.stderr
	@ rm -f $(MAKELOG)
	@ rm -f $(SUMMARYLOG)

cleans :
	rm -rf $(PDB)
	rm -f $(OBJS)

