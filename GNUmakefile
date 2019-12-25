 # Uversidade Federal do Rio de Janeiro
 # Escola Politecnica
 # Departamento de Eletronica e de Computacao
 # EEL270 - Computacao II - Turma 2019/1
 # Prof. Marcelo Luiz Drumond Lanza
 # Autor: Ewerton Vieira de Silles
 # Descricao: makefile para o CentOS

 # $Author: ewerton.silles $
 # $Date: 2019/11/05 03:47:36 $
 # $Log: GNUmakefile,v $
 # Revision 1.41  2019/11/05 03:47:36  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.40  2019/11/05 03:38:25  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.39  2019/11/05 01:46:25  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.38  2019/10/22 04:26:31  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.37  2019/10/20 05:36:29  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.36  2019/10/14 21:05:48  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.35  2019/10/02 02:10:50  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.34  2019/09/28 01:59:15  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.33  2019/09/28 00:20:20  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.32  2019/09/27 23:06:24  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.31  2019/09/27 02:33:19  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.30  2019/09/24 04:37:30  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.29  2019/09/24 02:20:25  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.28  2019/09/24 01:56:30  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.27  2019/09/23 22:55:21  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.26  2019/09/23 21:25:19  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.25  2019/09/15 00:24:03  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.24  2019/09/12 12:51:13  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.23  2019/09/12 12:37:40  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.22  2019/09/12 12:16:51  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.21  2019/09/11 13:30:57  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.20  2019/09/05 17:54:23  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.19  2019/09/05 17:42:00  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.18  2019/09/05 17:18:37  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.17  2019/09/05 16:38:11  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.16  2019/08/29 15:20:56  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.15  2019/08/29 15:06:30  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.14  2019/08/29 13:56:11  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.13  2019/08/28 22:04:16  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.12  2019/08/22 18:57:44  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.11  2019/08/22 18:47:42  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.10  2019/08/22 18:13:32  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.9  2019/08/21 01:41:25  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.8  2019/08/18 03:05:47  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.7  2019/08/18 00:55:27  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.6  2019/08/17 22:28:42  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.5  2019/08/17 15:58:00  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.4  2019/08/15 18:46:58  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.3  2019/08/15 17:44:29  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.2  2019/08/14 01:37:20  ewerton.silles
 # *** empty log message ***
 #
 # Revision 1.1  2019/08/13 23:16:47  ewerton.silles
 # Initial revision
 # 

OS = $(shell uname -s)

CC = gcc
LD = gcc

ifeq ($(cc), GCC)
CC = gcc
endif

ifeq ($(cc), CLANG)
CC = clang
endif

LD = $(CC)

AR = ar

AFLAGS = -r
CFLAGS = -Wall -std=c11
LFLAGS = -Wall -std=c11

AULA0101OBJS = aula0101.o
AULA0102OBJS = aula0102.o
AULA0103OBJS = aula0103.o
AULA0104OBJS = aula0104.o
AULA0105OBJS = aula0105.o
AULA0106OBJS = aula0106.o
AULA0107OBJS = aula0107.o
AULA0108OBJS = aula0108.o
AULA0202AOBJS = aula0201a.o aula0202.o
AULA0202BOBJS = aula0201b.o aula0202.o
AULA0202COBJS = aula0201c.o aula0202.o
AULA0202DOBJS = aula0201d.o aula0202.o
AULA0302AOBJS = aula0301a.o aula0302.o
AULA0302BOBJS = aula0301b.o aula0302.o
AULA0302COBJS = aula0301c.o aula0302.o
AULA0302DOBJS = aula0301d.o aula0302.o
AULA0402AOBJS = aula0401a.o aula0402.o
AULA0402BOBJS = aula0401b.o aula0402.o
AULA0402COBJS = aula0401c.o aula0402.o
AULA0402DOBJS = aula0401d.o aula0402.o
AULA0502AOBJS = aula0501a.o aula0502.o
AULA0502BOBJS = aula0501b.o aula0502.o
AULA0502COBJS = aula0501c.o aula0502.o
AULA0502DOBJS = aula0501d.o aula0502.o
AULA0502EOBJS = aula0501e.o aula0502.o
AULA0602AOBJS = aula0601.o aula0602a.o
AULA0602BOBJS = aula0601.o aula0602b.o
AULA0603AOBJS = aula0601.o aula0603a.o
AULA0603BOBJS = aula0601.o aula0603b.o
AULA0605AOBJS = aula0604.o aula0605a.o
AULA0605BOBJS = aula0604.o aula0605b.o
AULA0606AOBJS = aula0604.o aula0606a.o
AULA0606BOBJS = aula0604.o aula0606b.o
AULA0607OBJS = aula0601.o aula0607.o
AULA0609OBJS = aula0608.o aula0609.o
AULA0610OBJS = aula0608.o aula0610.o
AULA0702OBJS = aula0701.o aula0702.o
AULA0802OBJS = aula0801.o aula0802.o
AULA0902OBJS = aula0901.o aula0902.o
AULA0903OBJS = aula0901.o aula0903.o
AULA1002OBJS = aula1001.o aula1002.o
AULA1003OBJS = aula1001.o aula1003.o
AULA1004OBJS = aula1001.o aula1004.o

LIBMATEMATICAOBJS = aula0401a.o
LIBMATEMATICA = libmatematica.a
MATEMATICA = matematica
LIBBASE64OBJS = aula0901.o
LIBBASE64 = libbase64.a
BASE64 = base64

AULA01 = aula0101\
         aula0102\
         aula0103\
         aula0104\
         aula0105\
         aula0106\
         aula0107\
         aula0108

AULA02 = aula0202a\
         aula0202b\
         aula0202c\
         aula0202d

AULA03 = aula0302a\
         aula0302b\
         aula0302c\
         aula0302d

AULA04 = aula0402a\
         aula0402b\
         aula0402c\
         aula0402d

AULA05 = aula0502a\
         aula0502b\
         aula0502c\
         aula0502d\
         aula0502e

AULA06 = aula0602a\
         aula0602b\
         aula0603a\
         aula0603b\
         aula0605a\
         aula0605b\
         aula0606a\
         aula0606b\
         aula0607\
         aula0609\
         aula0610

AULA07 = aula0702

AULA08 = aula0802

AULA09 = aula0902\
         aula0903

AULA10 = aula1002\
         aula1003\
         aula1004

EXECS = $(AULA01)\
        $(AULA02)\
        $(AULA03)\
        $(AULA04)\
        $(AULA05)\
        $(AULA06)\
        $(AULA07)\
        $(AULA08)\
        $(AULA09)\
        $(AULA10)

LIBS = $(LIBMATEMATICA)\
       $(LIBBASE64)

ALL = $(EXECS)\
      $(LIBS)

#Regra Implicita
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

aula01: $(AULA01)

aula02: $(AULA02)

aula03: $(AULA03)

aula04: $(AULA04)

aula05: $(AULA05)

aula06: $(AULA06)

aula07: $(AULA07)

aula08: $(AULA08)

aula09: $(AULA09)

aula10: $(AULA10)

aula0101: $(AULA0101OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0101OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0102: $(AULA0102OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0102OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0103: $(AULA0103OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0103OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0104: $(AULA0104OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0104OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0105: $(AULA0105OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0105OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0106: $(AULA0106OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0106OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0107: $(AULA0107OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0107OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0108: $(AULA0108OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0108OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0202a: $(AULA0202AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0202b: $(AULA0202BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0202c: $(AULA0202COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202COBJS)
	cp $@ $@-$(OS)-$(CC)

aula0202d: $(AULA0202DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202DOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0302a: $(AULA0302AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0302b: $(AULA0302BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0302c: $(AULA0302COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302COBJS)
	cp $@ $@-$(OS)-$(CC)

aula0302d: $(AULA0302DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302DOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0402a: $(AULA0402AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0402b: $(AULA0402BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0402c: $(AULA0402COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402COBJS)
	cp $@ $@-$(OS)-$(CC)

aula0402d: $(AULA0402DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402DOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0502a: $(LIBMATEMATICA) $(AULA0502AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502AOBJS) -L. -l$(MATEMATICA)
	cp $@ $@-$(OS)-$(CC)

aula0502b: $(LIBMATEMATICA) $(AULA0502BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502BOBJS) -L. -l$(MATEMATICA)
	cp $@ $@-$(OS)-$(CC)

aula0502c: $(LIBMATEMATICA) $(AULA0502COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502COBJS) -L. -l$(MATEMATICA)
	cp $@ $@-$(OS)-$(CC)

aula0502d: $(LIBMATEMATICA) $(AULA0502DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502DOBJS) -L. -l$(MATEMATICA)
	cp $@ $@-$(OS)-$(CC)

aula0502e: $(AULA0502EOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502EOBJS) -lm
	cp $@ $@-$(OS)-$(CC)

aula0602a: $(AULA0602AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0602AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0602b: $(AULA0602BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0602BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0603a: $(AULA0603AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0603AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0603b: $(AULA0603BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0603BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0605a: $(AULA0605AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0605AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0605b: $(AULA0605BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0605BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0606a: $(AULA0606AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0606AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0606b: $(AULA0606BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0606BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0607: $(AULA0607OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0607OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0609: $(AULA0609OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0609OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0610: $(AULA0610OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0610OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0702: $(AULA0702OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0702OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0802: $(AULA0802OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0802OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0902: $(AULA0902OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0902OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0903: $(AULA0903OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0903OBJS)
	cp $@ $@-$(OS)-$(CC)

aula1002: $(LIBBASE64) $(AULA1002OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA1002OBJS) -L. -l$(BASE64)
	cp $@ $@-$(OS)-$(CC)

aula1003: $(LIBBASE64) $(AULA1003OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA1003OBJS) -L. -l$(BASE64)
	cp $@ $@-$(OS)-$(CC)

aula1004: $(LIBBASE64) $(AULA1004OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA1004OBJS) -L. -l$(BASE64)
	cp $@ $@-$(OS)-$(CC)

libmatematica.a: $(LIBMATEMATICAOBJS)
	ar -r $@ $(LIBMATEMATICAOBJS)

libbase64.a: $(LIBBASE64OBJS)
	ar -r $@ $(LIBBASE64OBJS)

clean:
	rm -f *.o $(ALL)

clean-all:
	rm -f *.o $(ALL) *-FreeBSD-* *-Linux-*

clean-freebsd:
	rm -f *.o $(ALL) *-FreeBSD-*

clean-linux:
	rm -f *.o $(ALL) *-Linux-*
