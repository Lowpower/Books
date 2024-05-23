struct alignas(16) A1 {  // C++11
  int x, y;
};
struct __attribute__((aligned(16))) A2 {  // compiler-specific attribute
  int x, y;
};
auto ptr1 = new int[100, 16];                    // 16B alignment, C++17
auto ptr2 = new int[100];                        // 4B alignment guarantee
auto ptr3 = __builtin_assume_aligned(ptr2, 16);  // compiler-specific attribute
auto ptr4 = new A1[10];                          // no aligment guarantee

// prefetch
for (int i = 0; i < size; i++) {
  auto data = array[i];
  __builtin_prefetch(array + i + 1, 0, 1);  // 2nd argument, '0' means read-only
  // 3th argument, '1' means
  // temporal locality=1, default=3
  // do some computation on 'data', e.g. CRC
}