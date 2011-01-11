/*
 * Generated by extract-headers.sh.
 */
#ifndef __ASM_CHECKPOINT_HDR_H_
#define __ASM_CHECKPOINT_HDR_H_
#if __s390x__
#include <asm-s390/checkpoint_hdr.h>
#elif __i386__ || __x86_64__
#include <asm-x86/checkpoint_hdr.h>
#else
#error "Architecture does not have definitons needed for checkpoint images."
#endif
#endif /* __ASM_CHECKPOINT_HDR_H_ */
