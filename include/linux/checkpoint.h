/*
 * Generated by extract-headers.sh.
 */
#ifndef _LINUX_CHECKPOINT_H_
#define _LINUX_CHECKPOINT_H_

/*
 *  Generic checkpoint-restart
 *
 *  Copyright (C) 2008-2009 Oren Laadan
 *
 *  This file is subject to the terms and conditions of the GNU General Public
 *  License.  See the file COPYING in the main directory of the Linux
 *  distribution for more details.
 */

#define CHECKPOINT_VERSION 6

/* checkpoint user flags */
#define CHECKPOINT_SUBTREE 0x1
#define CHECKPOINT_NETNS 0x2

/* restart user flags */
#define RESTART_TASKSELF 0x1
#define RESTART_FROZEN 0x2
#define RESTART_GHOST 0x4
#define RESTART_KEEP_LSM 0x8
#define RESTART_CONN_RESET 0x10

/* misc user visible */
#define CHECKPOINT_FD_NONE -1


#if __powerpc__

#	ifndef __NR_checkpoint
#		define __NR_checkpoint 324
#	endif

#	ifndef __NR_restart
#		define __NR_restart 325
#	endif

#elif __s390x__

#	ifndef __NR_checkpoint
#		define __NR_checkpoint 333
#	endif

#	ifndef __NR_restart
#		define __NR_restart 334
#	endif

#elif __i386__

#	ifndef __NR_checkpoint
#		define __NR_checkpoint 339
#	endif

#	ifndef __NR_restart
#		define __NR_restart 340
#	endif

#elif __x86_64__

#	ifndef __NR_checkpoint
#		define __NR_checkpoint 301
#	endif

#	ifndef __NR_restart
#		define __NR_restart 302
#	endif

#else
#error "Architecture does not have definitons for __NR_(checkpoint|restart)"
#endif
#endif /* _LINUX_CHECKPOINT_H_ */
