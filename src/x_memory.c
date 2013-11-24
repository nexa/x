#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#include "x_memory.h"

void *x_malloc(size_t size) {
  return malloc(size);
}

void x_free(void *memblock) {
  free(memblock);
}

void *x_memcpy(void *dest, const void *src, size_t count) {
  return memcpy(dest, src, count);
}

void *x_memset(void *dest, int c, size_t count) {
  return memset(dest, c, count);
}
