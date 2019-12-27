
CC	= cc
COPT	=

CA	= cadvise
#CA	= /opt/cadvise/bin/cadvise
CAOPT	= -pdb $(PDB) +wall cc +DD64 +w

GCC	= gcc
GCCWOPT_NO = -Wno-unused-parameter -Wno-missing-field-initializers
GCCWOPT = -Wundef -Wempty-body -Wfloat-equal -Wextra $(GCCWOPT_NO)
#ALL# GCCWOPT = -Wundef -Wempty-body -Wfloat-equal -Wextra
GCCPROTOOPT = -Wmissing-prototypes -Wstrict-prototypes
GCCOPT	= -Wall $(GCCWOPT) $(GCCPROTOOPT)

#----------
# CLANG
#----------
# DIAGNOSTIC FLAGS IN CLANG 
#  https://clang.llvm.org/docs/DiagnosticsReference.html
#  This page lists the diagnostic flags currently supported by Clang.
CLANG	= clang
CLANGOPT = -Weverything $(GCCWOPT_NO)

SRCDIR	= ./src
GETSRCS = `echo $(SRCDIR)/ca-*.c`
GETPROTOSRCS = `echo $(SRCDIR)/proto-*.c`
WARNING_SRCS = `echo $(SRCDIR)/wp-*.c`
ALLSRCS = $(GETSRCS) $(GETPROTOSRCS) $(WARNING_SRCS)

OBJS	= $(SRCS:.c=.o)

LOGDIR	= ./log
MAKELOG = $(LOGDIR)/makeall.log
SUMMARYLOG = $(LOGDIR)/makesummary.log

# CodeAdvisor
PDB = ./pdb

all : gcc

comp :
	make setup;
	-@ ( \
	make getinfo; \
	case "`uname -s`" in \
	"Linux" ) \
		make objs STAT_OPT="--format=%s"; \
		;; \
	"Darwin") \
		make objs STAT_OPT="-f %z"; \
		;; \
	"HP-UX" ) \
		make objs STAT_OPT="-f %z"; \
		;; \
	* ) \
		echo "ERROR: unknown OS : `uname -s`"; >&2 \
		;; \
	esac) 2>&1 |tee $(MAKELOG);

ca :
	make setup
	make SRCS="$(ALLSRCS)" CC=$(CA) COPT="$(CAOPT) $(COPT)" comp

gcc :
	make setup
	make SRCS="$(ALLSRCS)" CC=$(GCC) COPT="$(GCCOPT) $(GCCPROTOOPT) $(COPT)" comp

clang :
	make setup
	make SRCS="$(ALLSRCS)" CC=$(CLANG) COPT="$(CLANGOPT) $(COPT)" comp

proto :
	make setup
	make SRCS="$(GETPROTOSRCS)" CC=$(GCC) COPT="$(GCCOPT) $(GCCPROTOOPT) $(COPT)" comp

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
	@ echo "$(*F):stdout=`stat $(STAT_OPT) $(LOGDIR)/$(*F).stdout`:stderr=`stat $(STAT_OPT) $(LOGDIR)/$(*F).stderr`" >>$(SUMMARYLOG)

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

