
allexe = port_number port_number_check

all : $(allexe)

clean :
	rm -f $(allexe)

port_number : port_number.c
	cc -o $@ $<

port_number_check : port_number_check.c
	cc -o $@ $<
