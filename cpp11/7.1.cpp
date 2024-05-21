#include <assert.h>

inline void* aligned_malloc(size_t size, size_t alignment) {
  assert(!(alignment & (alignment -1)));
  size_t offset = sizeof(void*) + (--alignment);
  char *p = static_cast<char*>(malloc(offset + size));
  if (!p) {
    return nullptr
  }
  
  return r;
}

inline void aligned_free(void* p) {
  free(static_cast<void**>(p)[-1]);
}

int main() {
  return 0;
}