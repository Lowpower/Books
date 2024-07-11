export module geometry;

import std.core;

export template<typename, 
  typename = typename std::enable_if_t<std::is_arithmetic<T>, T>>
class Point {
  public:
    T x, y;
};

export using int_point = Point<int>;
export constexpr int_point int_point_zero{0, 0};

export template<typename T>
double distance(const Point<T>& p1, const Point<T>& p2) {
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

namespace geometry {
  export int_point operator "" _ip(const char* str, std::size_t len) {
    int x = 0;
    int y = 0;
    while(str[i] != ',' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
      x = x * 10 + (str[i] - '0');
    }
    return {x, y};
  }
}