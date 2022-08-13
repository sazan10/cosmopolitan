/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2020 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/calls/internal.h"
#include "libc/calls/ioctl.h"
#include "libc/calls/strace.internal.h"
#include "libc/calls/struct/winsize.h"
#include "libc/calls/struct/winsize.internal.h"
#include "libc/calls/syscall-sysv.internal.h"
#include "libc/dce.h"
#include "libc/intrin/asan.internal.h"
#include "libc/sysv/consts/termios.h"
#include "libc/sysv/errfuns.h"

/**
 * Returns width and height of terminal.
 *
 * @see ioctl(fd, TIOCGWINSZ, ws) dispatches here
 */
int ioctl_tiocgwinsz(int fd, ...) {
  int rc;
  va_list va;
  struct winsize *ws;
  va_start(va, fd);
  ws = va_arg(va, struct winsize *);
  va_end(va);
  if (IsAsan() && !__asan_is_valid(ws, sizeof(*ws))) {
    rc = efault();
  } else if (fd >= 0) {
    if (fd < g_fds.n && g_fds.p[fd].kind == kFdZip) {
      rc = enotty();
    } else if (!IsWindows()) {
      rc = sys_ioctl(fd, TIOCGWINSZ, ws);
    } else {
      rc = ioctl_tiocgwinsz_nt(g_fds.p + fd, ws);
    }
  } else {
    rc = einval();
  }
  STRACE("%s(%d) → %d% m", "ioctl_tiocgwinsz", fd, rc);
  return rc;
}
