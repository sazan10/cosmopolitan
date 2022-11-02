#include "libc/x/x.h"
/* clang-format off */

static _Atomic(void *) __gb18030ext_decmap_ptr;
static const unsigned char __gb18030ext_decmap_rodata[405] = {
  0xeb, 0x99, 0xcc, 0xce, 0x44, 0x11, 0xf8, 0x92, 0xfd, 0x31, 0x9b, 0x89, 0xb6,
  0x60, 0x4b, 0xd6, 0xc6, 0x2c, 0x42, 0x6a, 0x3e, 0x65, 0x32, 0xc0, 0xc0, 0xfa,
  0x24, 0xb0, 0xc8, 0xb2, 0x24, 0x06, 0x52, 0xc1, 0xe2, 0xbf, 0x6c, 0x4d, 0xb3,
  0xd9, 0x16, 0x21, 0x34, 0xce, 0x4f, 0x62, 0x9a, 0x87, 0x6c, 0xcc, 0xec, 0x24,
  0xa6, 0xab, 0x94, 0x86, 0x57, 0xc6, 0xc7, 0x0c, 0x5a, 0x87, 0x57, 0xfa, 0xc6,
  0x74, 0x82, 0xe1, 0x95, 0xc6, 0x40, 0x75, 0x30, 0x3d, 0x09, 0x61, 0xfe, 0x6b,
  0x16, 0x0a, 0x83, 0x29, 0xf5, 0x63, 0x2a, 0x21, 0x35, 0x9b, 0x52, 0x19, 0x68,
  0x01, 0x1a, 0x61, 0xde, 0xd8, 0xcd, 0x4c, 0x61, 0x3c, 0xa4, 0x6c, 0x4c, 0x21,
  0x18, 0x0f, 0xc9, 0x38, 0x5c, 0xf1, 0x31, 0x11, 0xaa, 0xe2, 0x49, 0x22, 0x0e,
  0x15, 0x0f, 0xa1, 0x2a, 0xae, 0x21, 0x2b, 0xb8, 0x9c, 0xc8, 0x74, 0x09, 0xcc,
  0x3f, 0x9f, 0x78, 0x21, 0x91, 0xe1, 0x2c, 0xcc, 0x10, 0xa6, 0x8d, 0x14, 0xa6,
  0xa9, 0x2f, 0x49, 0x1f, 0x93, 0x08, 0xc6, 0x07, 0xc1, 0x1c, 0xb7, 0x3b, 0x11,
  0x55, 0xc7, 0x82, 0x44, 0x42, 0x3a, 0xe6, 0x26, 0xe2, 0xb0, 0xec, 0x43, 0x02,
  0x6e, 0x4d, 0x6f, 0x13, 0xde, 0x25, 0x30, 0x74, 0xfe, 0x60, 0xef, 0xfa, 0xc1,
  0xfe, 0x32, 0x01, 0x14, 0x84, 0x09, 0xc4, 0xc4, 0xfb, 0xc3, 0x04, 0xac, 0x16,
  0xed, 0x48, 0x60, 0xd8, 0x9a, 0xb0, 0x2d, 0x61, 0x33, 0x50, 0x76, 0x43, 0x02,
  0xb1, 0x69, 0xe8, 0xff, 0x3e, 0xb6, 0xd9, 0x8c, 0x48, 0x86, 0xb4, 0x1d, 0x60,
  0x9b, 0x8c, 0x62, 0xfc, 0x9f, 0x78, 0x2a, 0xa6, 0xd8, 0x9f, 0xf1, 0xa8, 0x4e,
  0x9e, 0xab, 0xc0, 0x34, 0x0a, 0x46, 0x01, 0x69, 0x60, 0x97, 0x38, 0x88, 0xdc,
  0x2f, 0x3e, 0x1a, 0x12, 0xa3, 0x80, 0x44, 0x70, 0xfa, 0x3a, 0xeb, 0xaa, 0x67,
  0xac, 0x4c, 0x4c, 0xcb, 0x9f, 0xb1, 0xde, 0x13, 0x0f, 0xff, 0x2b, 0xc6, 0xb6,
  0xec, 0x19, 0xeb, 0xff, 0x93, 0xac, 0x3f, 0x18, 0xc5, 0x9b, 0xe5, 0xc4, 0xd6,
  0x69, 0xaf, 0x66, 0x9c, 0xb3, 0x87, 0x75, 0xed, 0x4e, 0x56, 0x85, 0x15, 0x4c,
  0x47, 0x99, 0xb6, 0xed, 0x64, 0x65, 0xda, 0xbd, 0x99, 0xf5, 0x00, 0xcb, 0x13,
  0xc6, 0x8f, 0x16, 0x53, 0x80, 0xba, 0xfa, 0x9f, 0xb1, 0xde, 0x70, 0x9b, 0xc4,
  0xf2, 0xd0, 0x6b, 0x52, 0x50, 0x7b, 0x10, 0x1b, 0x53, 0xc7, 0x33, 0xd6, 0xc9,
  0x93, 0x58, 0x39, 0x1f, 0x06, 0x1f, 0x09, 0xf9, 0xc4, 0x3c, 0x8d, 0x4d, 0xf3,
  0x5d, 0x3b, 0xeb, 0xb7, 0xb8, 0xad, 0x8f, 0x59, 0x79, 0x96, 0x31, 0x2a, 0xb5,
  0x26, 0xff, 0xca, 0x4c, 0x63, 0xe3, 0x62, 0x62, 0x61, 0x32, 0x62, 0xb7, 0x60,
  0xdc, 0xf3, 0x8b, 0x85, 0xe9, 0xf1, 0x3b, 0x16, 0x60, 0x7b, 0x2c, 0x38, 0xec,
  0x11, 0xb4, 0xb0, 0x5d, 0xc5, 0xf4, 0xe6, 0x15, 0xcb, 0x77, 0x7e, 0x9a, 0xfa,
  0x16, 0x00,
};

optimizesize void *__gb18030ext_decmap(void) {
  return xloadzd(&__gb18030ext_decmap_ptr,
                 __gb18030ext_decmap_rodata,
                 405, 2867, 2729, 2, 0x8e6ddc4au); /* 7.4203% profit */
}
