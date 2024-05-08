#ifndef DEFS_H
#define DEFS_H
#include <stddef.h> // For size_t and ptrdiff_t
#include <stdint.h> // For uintptr_t

typedef char* string;

#ifndef PTRDIFF_T_DEFINED
typedef intptr_t ptrdiff_t;
#endif

#ifndef NORETURN_DEFINED
typedef void noreturn;
#endif

void *memset(void *s, int c, size_t n) {
    char *p = (char *)s;
    for (size_t i = 0; i < n; ++i) {
        *p++ = (char)c;
    }
    return s;
}


#if defined(__LP64__) || defined(_LP64)
    typedef uint64_t uintptr;
#elif defined(__ILP32__) || defined(_ILP32)
    typedef uint32_t uintptr;
#else
    #error "Pointer size must be 4 or 8 bytes"
#endif

#endif