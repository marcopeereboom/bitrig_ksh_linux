/*	$OpenBSD: config.h,v 1.14 2011/03/14 21:20:00 okan Exp $	*/

/* config.h.  NOT generated automatically. */

/*
 * This file, config.h, which is a part of pdksh (the public domain ksh),
 * is placed in the public domain.  It comes with no licence, warranty
 * or guarantee of any kind (i.e., at your own risk).
 */

#define nitems(_a)  (sizeof((_a)) / sizeof((_a)[0]))

#include <time.h>
#ifndef timespeccmp
#define	timespeccmp(tsp, usp, cmp)					\
	(((tsp)->tv_sec == (usp)->tv_sec) ?				\
	    ((tsp)->tv_nsec cmp (usp)->tv_nsec) :			\
	    ((tsp)->tv_sec cmp (usp)->tv_sec))
#endif

#include <bsd/string.h>
#include <bsd/stdio.h>
#include <bsd/stdlib.h>
#include <bsd/sys/queue.h>

/* flock and O_EXLOCK */
#include <sys/file.h>
#include <sys/fcntl.h>
#define O_EXLOCK LOCK_EX

#include <sys/statfs.h>
#define MNT_RDONLY MS_RDONLY

/* CHILD_MAX */
#include <bits/posix1_lim.h>
#define CHILD_MAX _POSIX_CHILD_MAX

#define _PW_NAME_LEN 31 /* max length, not counting NUL */
#define srand_deterministic srand

#ifndef CONFIG_H
#define CONFIG_H

/* Include emacs editing? */
#define EMACS 1

/* Include vi editing? */
#define VI 1

/* Include job control? */
#define JOBS 1

/* Include brace-expansion? */
#define BRACE_EXPAND 1

/* Include any history? */
#define HISTORY 1

/* Strict POSIX behaviour? */
/* #undef POSIXLY_CORRECT */

/* Specify default $ENV? */
/* #undef DEFAULT_ENV */

/*
 * End of configuration stuff for PD ksh.
 */

#if defined(EMACS) || defined(VI)
# define	EDIT
#else
# undef		EDIT
#endif

/* Super small configuration-- no editing. */
#if defined(EDIT) && defined(NOEDIT)
# undef EDIT
# undef EMACS
# undef VI
#endif

/* Editing implies history */
#if defined(EDIT) && !defined(HISTORY)
# define HISTORY
#endif /* EDIT */

#endif /* CONFIG_H */
