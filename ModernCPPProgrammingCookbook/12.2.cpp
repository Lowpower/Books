export module geometry.core;

import std.core;

export template<typename T, typename std::enable_if_t<std::is_arithmetic<T>, T>>
class Point {
  public:
    T x, y;
};

export module geometry.io;

import geometry.core;

export void print(const Point<T>& p) {
  std::cout << p.x << ", " << p.y << std::endl;
}