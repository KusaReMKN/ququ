CC=	cc
CFLAGS=	-O -Wall
RM=	rm -f
SHELL=	/bin/sh

all: ququ

ququ: ququ.c
	$(CC) $(CFLAGS) -o ququ ququ.c

.PHONY: clean
clean:
	$(RM) ququ
