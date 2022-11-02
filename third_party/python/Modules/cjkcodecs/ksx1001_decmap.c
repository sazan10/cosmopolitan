#include "libc/x/x.h"
/* clang-format off */

static _Atomic(void *) ksx1001_decmap_ptr;
static const unsigned char ksx1001_decmap_rodata[] = {
  0xed, 0xd0, 0xb1, 0x2b, 0xc4, 0x71, 0x18, 0xc7, 0xf1, 0xdf, 0xd7, 0xef, 0x38,
  0xe7, 0x1c, 0x0e, 0xe7, 0x70, 0xce, 0xf5, 0x19, 0x64, 0x30, 0xc8, 0x20, 0x83,
  0x41, 0x06, 0x93, 0x24, 0x83, 0x41, 0x94, 0x88, 0x24, 0xc3, 0xa5, 0x8b, 0x48,
  0x3d, 0x06, 0x19, 0x0c, 0x32, 0xc8, 0x60, 0x90, 0x41, 0x29, 0x49, 0x8a, 0x41,
  0x94, 0x0c, 0x06, 0x19, 0x0c, 0x32, 0xc8, 0x60, 0x90, 0xc1, 0x20, 0x83, 0x0c,
  0x06, 0x91, 0xb7, 0x2c, 0xfe, 0x03, 0xcb, 0x7d, 0xea, 0xd5, 0x33, 0x7d, 0x7a,
  0x7a, 0x1e, 0xcf, 0xfb, 0xff, 0x38, 0x4f, 0x36, 0xe8, 0x69, 0x6c, 0x9b, 0x19,
  0x70, 0xb2, 0x61, 0xa7, 0x99, 0x13, 0xa7, 0x91, 0x2f, 0xa7, 0x74, 0x57, 0x8e,
  0x6c, 0x17, 0x21, 0x5f, 0x99, 0x01, 0x5f, 0xd3, 0x07, 0xbe, 0x26, 0xff, 0x76,
  0xfd, 0x80, 0x6c, 0x08, 0x67, 0x48, 0xe6, 0xca, 0xe6, 0x70, 0x87, 0x96, 0x3c,
  0xd9, 0x1a, 0xde, 0xd0, 0x13, 0x94, 0xed, 0x23, 0x92, 0x2f, 0x9b, 0xc0, 0x25,
  0xea, 0x43, 0xb2, 0x45, 0x3c, 0xa2, 0xbd, 0x40, 0xb6, 0x89, 0x4f, 0xf4, 0x87,
  0x65, 0xc7, 0x88, 0x17, 0xca, 0xa6, 0x70, 0x83, 0x9f, 0x3d, 0x4d, 0x11, 0xd9,
  0x0a, 0x5e, 0xd0, 0x59, 0x24, 0xdb, 0x41, 0xb0, 0x58, 0x36, 0x8a, 0x73, 0xa8,
  0x44, 0x36, 0x8f, 0x7b, 0xb4, 0x46, 0x65, 0xeb, 0x78, 0x47, 0x6f, 0xa9, 0xec,
  0x10, 0xd1, 0x32, 0x59, 0x1a, 0x57, 0x68, 0x28, 0x97, 0x2d, 0xe1, 0x09, 0x1d,
  0x31, 0xd9, 0x16, 0x5c, 0x05, 0x3f, 0xc0, 0x29, 0x12, 0x71, 0xd9, 0x2c, 0x6e,
  0xd1, 0x5c, 0x29, 0x5b, 0xc5, 0x2b, 0xba, 0xab, 0x64, 0x7b, 0x08, 0x57, 0xcb,
  0xc6, 0x71, 0x81, 0xba, 0x84, 0x6c, 0x01, 0x0f, 0x68, 0xab, 0x91, 0x6d, 0xe0,
  0x03, 0x7d, 0x49, 0xd9, 0x11, 0x62, 0xb5, 0xb2, 0x0c, 0xae, 0xd1, 0x98, 0x92,
  0x2d, 0xe3, 0x39, 0xf5, 0x7b, 0x53, 0x36, 0xd9, 0x7c, 0x03,
};

optimizesize void *ksx1001_decmap(void) {
  return xload(&ksx1001_decmap_ptr,
               ksx1001_decmap_rodata,
               270, 1024); /* 26.3672% profit */
}
