#
# Copyright (C) 2017 T.Furukawa
# $Id$
#
# img2html の makefile です。
#
# WindowsでBuildする場合は、mingwを使用して下さい。また、Windows だと実
# 行時に文字化けするので、cp982を有効にしてbuildして下さい(cygwindの
# Consoleを utf-8 で実行する方法もありますが…)。linuxでクロスコンパイ
# ルする場合は、実行ファイルに拡張子が付与されませんので、EXE環境変数も
# 指定した方が良いでしょう。纏めると
#
#      make CC=i586-mingw32msvc-gcc EXEC_CHARSET=cp932 EXE=img2html.exe
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
