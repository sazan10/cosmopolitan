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
#include "libc/bits/bits.h"
#include "libc/mem/mem.h"
#include "libc/rand/rand.h"
#include "libc/str/str.h"
#include "libc/testlib/ezbench.h"
#include "libc/testlib/testlib.h"

TEST(strchr, blank) {
  const char *const blank = "";
  EXPECT_EQ(NULL, strchr(blank, '#'));
  EXPECT_EQ(blank, strchr(blank, '\0'));
}

TEST(strchr, text) {
  char buf[] = "hellothere";
  EXPECT_STREQ("there", strchr(buf, 't'));
}
TEST(strchr, testsse) {
  char buf[] = "hellohellohellohellohellohellohellohello"
               "theretheretheretheretheretheretherethere";
  EXPECT_STREQ("theretheretheretheretheretheretherethere", strchr(buf, 't'));
}
TEST(rawmemchr, text) {
  char buf[] = "hellothere";
  EXPECT_STREQ("there", rawmemchr(buf, 't'));
}
TEST(strchrnul, text) {
  char buf[] = "hellothere";
  EXPECT_STREQ("there", strchrnul(buf, 't'));
}

TEST(strchr, nulTerminator) {
  char buf[] = "hellothere";
  EXPECT_STREQ("", strchr(buf, '\0'));
}
TEST(rawmemchr, nulTerminator) {
  char buf[] = "hellothere";
  EXPECT_STREQ("", rawmemchr(buf, '\0'));
}
TEST(strchrnul, nulTerminator) {
  char buf[] = "hellothere";
  EXPECT_STREQ("", strchrnul(buf, '\0'));
}

TEST(strchr, notFound_returnsNul) {
  char buf[] = "hellothere";
  EXPECT_EQ(NULL, strchr(buf, 'z'));
}
TEST(strchrnul, notFound_returnsPointerToNulByte) {
  char buf[] = "hi";
  EXPECT_STREQ("", strchrnul(buf, 'z'));
  EXPECT_EQ(&buf[2], strchrnul(buf, 'z'));
}

char *strchr$pure(const char *s, int c) {
  char *r;
  for (c &= 0xff;; ++s) {
    if ((*s & 0xff) == c) return (char *)s;
    if (!*s) return NULL;
  }
}

TEST(strchr, fuzz) {
  char *p;
  int i, j;
  p = calloc(1, 64);
  for (i = -2; i < 257; ++i) {
    for (j = 0; j < 17; ++j) {
      rngset(p, 63, rand64, -1);
      ASSERT_EQ(strchr(p + j, i), strchr$pure(p + j, i));
    }
  }
  free(p);
}

BENCH(strchr, bench) {
  EZBENCH2("strchr 0", donothing, EXPROPRIATE(strchr(VEIL("r", ""), 0)));
  EZBENCH2("strchr 5", donothing, EXPROPRIATE(strchr(VEIL("r", "hello"), 'o')));
  EZBENCH2("strchr 8", donothing,
           EXPROPRIATE(strchr(VEIL("r", "hellzzzo"), 'o')));
  EZBENCH2("strchr 17", donothing,
           EXPROPRIATE(strchr(VEIL("r", "hellzzzhellzzzeeo"), 'o')));
  EZBENCH2("strchr 34", donothing,
           EXPROPRIATE(
               strchr(VEIL("r", "hellzzzhellzzzeeAhellzzzhellzzzeeo"), 'o')));
}

char *memchr$pure(const char *m, int c, size_t n) {
  const unsigned char *p, *pe;
  for (c &= 0xff, p = (const unsigned char *)m, pe = p + n; p < pe; ++p) {
    if (*p == c) return p;
  }
  return NULL;
}

TEST(memchr, fuzz) {
  char *p;
  int i, j;
  p = malloc(64);
  for (i = -2; i < 257; ++i) {
    for (j = 0; j < 17; ++j) {
      rngset(p, 64, rand64, -1);
      ASSERT_EQ(memchr(p + j, i, 64 - j), memchr$pure(p + j, i, 64 - j));
    }
  }
  free(p);
}

char *strchrnul$pure(const char *s, int c) {
  char *r;
  for (c &= 0xff;; ++s) {
    if ((*s & 0xff) == c) return (char *)s;
    if (!*s) return s;
  }
}

TEST(strchrnul, fuzz) {
  char *p;
  int i, j;
  p = calloc(1, 64);
  for (i = -2; i < 257; ++i) {
    for (j = 0; j < 17; ++j) {
      rngset(p, 63, rand64, -1);
      ASSERT_EQ(strchrnul(p + j, i), strchrnul$pure(p + j, i));
    }
  }
  free(p);
}

void *rawmemchr$pure(const void *m, int c) {
  const unsigned char *s;
  for (c &= 255, s = m;; ++s) {
    if (*s == c) return s;
  }
}

TEST(rawmemchr, fuzz) {
  char *p;
  int i, j;
  p = malloc(64);
  for (i = -2; i < 257; ++i) {
    for (j = 0; j < 17; ++j) {
      rngset(p, 63, rand64, -1);
      p[63] = i;
      ASSERT_EQ(rawmemchr(p + j, i), rawmemchr$pure(p + j, i));
    }
  }
  free(p);
}
