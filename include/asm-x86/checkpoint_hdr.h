/*
 * Generated by extract-headers.sh.
 */
#ifndef __ASM_X86_CHECKPOINT_HDR_H_
#define __ASM_X86_CHECKPOINT_HDR_H_

/*
 *  Checkpoint/restart - architecture specific headers x86
 *
 *  Copyright (C) 2008-2009 Oren Laadan
 *
 *  This file is subject to the terms and conditions of the GNU General Public
 *  License.  See the file COPYING in the main directory of the Linux
 *  distribution for more details.
 */

#include <linux/types.h>

/*
 * To maintain compatibility between 32-bit and 64-bit architecture flavors,
 * keep data 64-bit aligned: use padding for structure members, and use
 * __attribute__((aligned (8))) for the entire structure.
 *
 * Quoting Arnd Bergmann:
 *   "This structure has an odd multiple of 32-bit members, which means
 *   that if you put it into a larger structure that also contains 64-bit
 *   members, the larger structure may get different alignment on x86-32
 *   and x86-64, which you might want to avoid. I can't tell if this is
 *   an actual problem here. ... In this case, I'm pretty sure that
 *   sizeof(ckpt_hdr_task) on x86-32 is different from x86-64, since it
 *   will be 32-bit aligned on x86-32."
 */

/* i387 structure seen from kernel/userspace */

/* arch dependent header types */
enum {
	CKPT_HDR_CPU_FPU = 201,
#define CKPT_HDR_CPU_FPU CKPT_HDR_CPU_FPU
	CKPT_HDR_MM_CONTEXT_LDT,
#define CKPT_HDR_MM_CONTEXT_LDT CKPT_HDR_MM_CONTEXT_LDT
};

/* arch dependent constants */
#define CKPT_ARCH_NSIG 64
#define CKPT_TTY_NCC 8

struct ckpt_hdr_header_arch {
	struct ckpt_hdr h;
	/* FIXME: add HAVE_HWFP */
	__u16 has_fxsr;
	__u16 has_xsave;
	__u16 xstate_size;
	__u16 _pading;
} __attribute__((aligned(8)));

struct ckpt_hdr_thread {
	struct ckpt_hdr h;
	__u32 thread_info_flags;
	__u16 gdt_entry_tls_entries;
	__u16 sizeof_tls_array;
} __attribute__((aligned(8)));

/* designed to work for both x86_32 and x86_64 */
struct ckpt_hdr_cpu {
	struct ckpt_hdr h;
	/* see struct pt_regs (x86_64) */
	__u64 r15;
	__u64 r14;
	__u64 r13;
	__u64 r12;
	__u64 bp;
	__u64 bx;
	__u64 r11;
	__u64 r10;
	__u64 r9;
	__u64 r8;
	__u64 ax;
	__u64 cx;
	__u64 dx;
	__u64 si;
	__u64 di;
	__u64 orig_ax;
	__u64 ip;
	__u64 sp;

	__u64 flags;

	/* segment registers */
	__u64 fs;
	__u64 gs;

	__u16 fsindex;
	__u16 gsindex;
	__u16 cs;
	__u16 ss;
	__u16 ds;
	__u16 es;

	__u32 used_math;

	/* debug registers */
	__u64 debugreg0;
	__u64 debugreg1;
	__u64 debugreg2;
	__u64 debugreg3;
	__u64 debugreg6;
	__u64 debugreg7;

	/* thread_xstate contents follow (if used_math) */
} __attribute__((aligned(8)));

#define CKPT_X86_SEG_NULL 0
#define CKPT_X86_SEG_USER32_CS 1
#define CKPT_X86_SEG_USER32_DS 2
#define CKPT_X86_SEG_USER64_CS 3
#define CKPT_X86_SEG_USER64_DS 4
#define CKPT_X86_SEG_TLS 0x4000 /* 0100 0000 0000 00xx */
#define CKPT_X86_SEG_LDT 0x8000 /* 100x xxxx xxxx xxxx */

struct ckpt_hdr_mm_context {
	struct ckpt_hdr h;
	__u64 vdso;
	__u32 ldt_entry_size;
	__u32 nldt;
} __attribute__((aligned(8)));



#endif /* __ASM_X86_CHECKPOINT_HDR_H_ */
