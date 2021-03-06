#	$OpenBSD: Makefile,v 1.28 2012/04/30 03:51:29 djm Exp $

PREFIX =	/usr
BINDIR = 	$(DESTDIR)/bin
MANDIR =	$(DESTDIR)$(PREFIX)/man

PROG=		ksh
SRCS=		alloc.c c_ksh.c c_sh.c c_test.c c_ulimit.c edit.c emacs.c \
		eval.c exec.c expr.c history.c io.c jobs.c lex.c mail.c \
		main.c mknod.c misc.c path.c shf.c syn.c table.c trap.c \
		tree.c tty.c var.c version.c vi.c

DEFS=		-Wall -D_GNU_SOURCE -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
CFLAGS+=	${DEFS} -I. -I${.CURDIR}
LDADD+=	-lbsd
MAN=		ksh.1 sh.1
NOGCCERROR=	1

LINKS=		${BINDIR}/ksh ${BINDIR}/rksh
LINKS+=		${BINDIR}/ksh ${BINDIR}/sh
MLINKS=		ksh.1 rksh.1


check test:
	/usr/bin/perl ${.CURDIR}/tests/th -s ${.CURDIR}/tests -p ./ksh -C \
	    pdksh,sh,ksh,posix,posix-upu

.include <bsd.prog.mk>
