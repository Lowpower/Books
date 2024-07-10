#include <iostream>

struct alignas(4) foo {
  char a;
  char b;
};

struct alignas(4) bar {
  alignas(2) char a;
  alignas(8) char b;
};

alignas(8) int a;
alignas(256) long b[4];

struct foo1 {
  char a;
};

struct foo2 {
  char a;
  char b;
};

struct foo3 {
  char a;
  int b;
};

struct foo4 {
  int a;
  char b;
  float c;
  double d;
  bool e;
};

int main() {
  auto align = alignof(foo);
  auto align2 = alignof(bar);
  std::cout << align << " " << align2 << std::endl;
  std::cout << alignof(a) << " " << alignof(b) << std::endl;
  std::cout << sizeof(foo1) << " " << sizeof(foo2) << " " << sizeof(foo3) << " "
            << sizeof(foo4) << std::endl;
  return 0;
}