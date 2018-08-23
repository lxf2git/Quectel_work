#ifndef _COMMON_H
#define _COMMON_H

#define printf(...) (((int(*)(const char *format, ...))0x43e11a2c)(__VA_ARGS__))

#endif
