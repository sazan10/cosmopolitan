#ifndef COSMOPOLITAN_LIBC_CALLS_STRUCT_SIGINFO_H_
#define COSMOPOLITAN_LIBC_CALLS_STRUCT_SIGINFO_H_
#include "libc/calls/struct/sigval.h"
#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_

struct siginfo {
  int32_t si_signo;
  int32_t si_errno;
  int32_t si_code; /* {SICODE,SEGV,ILL,FPE,POLL}_xxx */
  union {
    struct {
      union {
        struct {
          int32_t si_pid;
          uint32_t si_uid;
        };
        struct {
          int32_t si_timerid; /* SIGALRM */
          int32_t si_overrun;
        };
      };
      union {
        union sigval si_value; /* provided by third arg of sigqueue(2) */
        struct {
          int32_t si_status;
          int64_t si_utime;
          int64_t si_stime;
        };
      };
    };
    struct {
      void *si_addr;
      int16_t si_addr_lsb;
      union {
        struct {
          void *si_lower;
          void *si_upper;
        };
        uint32_t si_pkey;
      };
    };
    struct {
      int64_t si_band; /* SIGPOLL */
      int32_t si_fd;
    };
    struct {
      void *si_call_addr;
      int32_t si_syscall;
      uint32_t si_arch;
    };
    char __ignoreme[128 - 2 * sizeof(int32_t) - sizeof(int64_t)];
  };
};

typedef struct siginfo siginfo_t;

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_LIBC_CALLS_STRUCT_SIGINFO_H_ */
