#include <string>
#include <iostream>

struct TextVerticalAlignment {
  static const int Top = 0;
  static const int Center = 1;
  static const int Bottom = 2;
};

struct TextHorizontalAlignment {
  static const int Left = 0;
  static const int Center = 1;
  static const int Right = 2;
};

struct control {
  const int DefaultHeight = 0;
  const int DefaultWidth = 0;

  int verticalAlignment = TextVerticalAlignment::Top;
  int horizontalAlignment = TextHorizontalAlignment::Left;
  std::string text;

  control(const std::string &text) : text(text) {}
};

struct Point {
  double x;
  double y;
  Point(double x, double y) : x(x), y(y) {}
};

struct foo {
  foo() {
    std::cout << "default constructor" << std::endl;
  }
  foo(const foo &) { std::cout << "copy constructor" << std::endl; }
  foo(foo &&) { std::cout << "move constructor" << std::endl; }
  foo &operator=(const foo &) {
    std::cout << "copy assignment operator" << std::endl;
    return *this;
  }
  foo &operator=(foo &&) {
    std::cout << "move assignment operator" << std::endl;
    return *this;
  }
  ~foo() { std::cout << "destructor" << std::endl; }
};

struct bar {
  foo f;
  bar(const foo &&value) : f(std::move(value)) {}
};

enum class TextFlow {
  LeftToRight,
  RightToLeft,
  TopToBottom,
  BottomToTop,
};

struct Control2 {
  const int DefaultHeight = 0;
  const int DefaultWidth = 0;

  TextFlow textFlow = TextFlow::LeftToRight;
  std::string text;
  Control2(const std::string &text) : text(text) {}
};

int main() {
  foo f;
  bar b(std::move(f));
  return 0;
}
