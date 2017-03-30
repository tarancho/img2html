# $Id$
#

CFLAGS = -g -Wall -W -Wformat=2 -Wcast-qual -Wcast-align -Wwrite-strings \
	-Wconversion -Wfloat-equal -Wpointer-arith \
	--input-charset=utf-8

OBJS = main.o base64.o

EXE = img2html

$(EXE) : $(OBJS)
	$(CC) -o $@ $(OBJS)

etags :
	etags *.[ch]

clean :
	rm -f *~ *.o

clean-all : clean
	rm -f $(EXE)
