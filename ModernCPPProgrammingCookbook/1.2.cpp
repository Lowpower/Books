#include <string>
#include <vector>

using byte = unsigned char;
using byte_ptr = unsigned char*;
using array_t = int[10];
using fn = void(byte, double);

byte b{42};
byte_ptr p = new byte[10] {0};
array_t a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void func(byte b, double d) {}

fn* f = func;

template <typename T>
class custom_allocator {
  public:
    using value_type = T;
};

template<typename T>
using vec_t = std::vector<T, custom_allocator<T>>;

vec_t<int> v1;
vec_t<std::string> vs;

int main() {
  return 0;
}