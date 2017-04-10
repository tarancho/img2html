#
# Copyright (C) 2017 T.Furukawa
# $Id$
#
# img2html の makefile です。
#
# WindowsでBuildする場合は、mingwを使用して下さい。また、Windows だと実
# 行時の文字コードや実行ファイル名の名称にも制限がありますので、環境変
# 数 WIN を定義してbuildして下さい。纏めると
#
#      make CC=i586-mingw32msvc-gcc WIN=1
#
# といった感じで。mingwのパスは環境によって異なると思いますので、適宜修
# 正してください。

EXEC_CHARSET=utf-8

CFLAGS = -g -Wall -W -Wformat=2 -Wcast-qual -Wcast-align -Wwrite-strings \
	-Wconversion -Wfloat-equal -Wpointer-arith \
	--input-charset=utf-8 \
	--exec-charset=$(EXEC_CHARSET)

OBJS = main.o base64.o

EXE = img2html

ifdef WIN
	EXE = img2html.exe
	EXEC_CHARSET=cp932
endif

$(EXE) : $(OBJS)
	$(CC) -o $@ $(OBJS)

etags :
	etags *.[ch]

clean :
	rm -f *~ *.o

clean-all : clean
	rm -f $(EXE) $(EXE).exe

# Local Variables:
# mode: makefile
# coding: utf-8-unix
# End:
