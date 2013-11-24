#ifndef _X_MEMORY_H_
#define _X_MEMORY_H_

void *x_malloc(size_t size);

void x_free(void* memblock);

void *x_memcpy(void *dest, const void *src, size_t conut);

void *x_memset(void *dest, int c, size_t count);

#define x_zero(dest) \
  x_memset(dest, 0, sizeof(dest))

#endif /* _X_MEMORY_H */
