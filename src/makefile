#
# Copyright (C) 2017 T.Furukawa
# $Id$
#
# img2html の makefile です。
#
# WindowsでBuildする場合は、mingwを使用して下さい。以下に例を示します。
#
#      make CC=/usr/bin/i686-pc-mingw32-gcc.exe
#
# また、Windows だと実行時に文字化けするので、cp982を有効にしてbuildし
# て下さい(cygwindのConsoleを utf-8 で実行する方法もありますが…)。纏め
# ると
#
#      make CC=/usr/bin/i686-pc-mingw32-gcc.exe EXEC_CHARSET=cp932
#
# といった感じで。

EXEC_CHARSET=utf-8

CFLAGS = -g -Wall -W -Wformat=2 -Wcast-qual -Wcast-align -Wwrite-strings \
	-Wconversion -Wfloat-equal -Wpointer-arith \
	--input-charset=utf-8 \
	--exec-charset=$(EXEC_CHARSET)

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

# Local Variables:
# mode: makefile
# coding: utf-8-unix
# End:
