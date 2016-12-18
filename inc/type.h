#ifndef __TYPE_H__
#define __TYPE_H__

typedef unsigned char       BYTE;
typedef unsigned char       UINT8;
typedef unsigned short      UINT16;
typedef unsigned long       UINT32;

#define SWAP_16(x)	(x & 0xFF00 >> 8) | (x & 0x00FF << 8)
#define SWAP_32(x)	(x & 0xFF000000 >> 24) | (x & 0x00FF0000 >> 8) | \
					(x & 0x0000FF00 << 8) | (x & 0x000000FF << 24)


#endif //__TYPE_H__